#include "hardware/PumpController.h"

#include <stdexcept>

#include "PinConfig.h"
#include "utils/Logger.h"

PumpController::PumpController(unsigned int chipNo, unsigned int pumpPin,
                               DriveMode mode)
    : chipNo_(chipNo), pumpPin_(pumpPin), mode_(mode) {}

PumpController::~PumpController() { shutdown(); }

bool PumpController::init() {
  if (initialised_)
    return true;

  try {
    const std::string chipPath = "/dev/gpiochip" + std::to_string(chipNo_);
    chip_.emplace(chipPath);

    pumpLine_ = chip_->get_line(pumpPin_);
    ledLine_ = chip_->get_line(FILL_LED_PIN);

    gpiod::line_request req;
    req.request_type = gpiod::line_request::DIRECTION_OUTPUT;
    req.consumer = "pump_controller";

    pumpLine_->request(req, offValue());
    ledLine_->request(req, 0);

    running_ = false;
    initialised_ = true;

    Logger::info("PumpController initialised via libgpiod (chip=" +
                 std::to_string(chipNo_) + ", pin=" + std::to_string(pumpPin_) +
                 ", mode=" +
                 std::string((mode_ == DriveMode::RELAY_ACTIVE_LOW)
                                 ? "RELAY(active-LOW)"
                                 : "TRANSISTOR(active-HIGH)") +
                 ")");
    return true;
  } catch (const std::exception &e) {
    Logger::error("PumpController::init() error: " + std::string(e.what()));
    return false;
  }
}

void PumpController::shutdown() {
  if (initialised_) {
    if (pumpLine_)
      pumpLine_->set_value(offValue());
    if (ledLine_)
      ledLine_->set_value(0);
  }

  running_ = false;
  initialised_ = false;
  pumpLine_.reset();
  ledLine_.reset();
  chip_.reset();
  Logger::info("PumpController shut down (pump OFF).");
}

void PumpController::turnOn() {
  if (!initialised_ || running_)
    return;

  if (pumpLine_ && ledLine_) {
    pumpLine_->set_value(onValue());
    ledLine_->set_value(1);
  }

  running_ = true;
  Logger::info("Pump started!");
}

void PumpController::turnOff() {
  if (!initialised_ || !running_)
    return;

  if (pumpLine_ && ledLine_) {
    pumpLine_->set_value(offValue());
    ledLine_->set_value(0);
  }

  running_ = false;
  Logger::info("Pump stopped.");
}

bool PumpController::isRunning() const { return running_; }

#ifdef AQUAFLOW_TESTING
void PumpController::enableSimulationForTest() {
  initialised_ = true;
  running_ = false;
  pumpLine_.reset();
  ledLine_.reset();
  chip_.reset();
}
#endif

int PumpController::onValue() const {
  return (mode_ == DriveMode::RELAY_ACTIVE_LOW) ? 0 : 1;
}

int PumpController::offValue() const {
  return (mode_ == DriveMode::RELAY_ACTIVE_LOW) ? 1 : 0;
}
