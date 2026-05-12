#include "hardware/FlowMeter.h"

#include <stdexcept>
#include <string>

#include "utils/Logger.h"

bool FlowMeter::init() {
  if (running_)
    return true;
  try {
    setupGpio();
    running_ = true;
    pulseCount_ = 0;
    edgeThread_ = std::thread(&FlowMeter::edgeWorker, this);
    return true;
  } catch (const std::exception &e) {
    shutdown();
    return false;
  }
}

#ifdef AQUAFLOW_TESTING
void FlowMeter::injectPulseCountForTest(int pulseCount) {
  pulseCount_.store(pulseCount);
}
#endif

void FlowMeter::shutdown() {
  running_ = false;
  if (edgeThread_.joinable())
    edgeThread_.join();
  line_.reset();
  chip_.reset();
}

void FlowMeter::resetCount() { pulseCount_.store(0); }

int FlowMeter::getPulseCount() const { return pulseCount_.load(); }

double FlowMeter::getVolumeML() const {
  return static_cast<double>(pulseCount_.load()) * mlPerPulse_;
}

void FlowMeter::setupGpio() {
  const std::string chipPath = "/dev/gpiochip" + std::to_string(chipNo_);
  chip_.emplace(chipPath);

  line_ = chip_->get_line(pinNo_);

  gpiod::line_request req;
  req.request_type = gpiod::line_request::EVENT_FALLING_EDGE;
  req.consumer = "flow_meter";
  req.flags = gpiod::line_request::FLAG_BIAS_PULL_UP;

  line_->request(req);
}

void FlowMeter::edgeWorker() {
  lastPulseTime_ = std::chrono::steady_clock::time_point{};

  try {
    while (running_) {
      if (line_->event_wait(std::chrono::milliseconds(200))) {
        gpiod::line_event event = line_->event_read();

        if (event.event_type == gpiod::line_event::FALLING_EDGE) {
          auto now = std::chrono::steady_clock::now();
          auto gap = std::chrono::duration_cast<std::chrono::milliseconds>(
                         now - lastPulseTime_)
                         .count();

          // Real water flow pulses are around 10 ms apart at max rate, so a
          // 5 ms minimum gap filters EMI bursts without dropping valid pulses.
          if (gap >= DEBOUNCE_MS) {
            pulseCount_++;
            lastPulseTime_ = now;
          }
        }
      }
    }
  } catch (const std::exception &e) {
    Logger::error("FlowMeter hardware fault (thread aborted): " +
                  std::string(e.what()));
    running_ = false;
  }
}
