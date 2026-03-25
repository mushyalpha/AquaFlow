#include "monitor/Monitor.h"
#include "utils/Logger.h"

#include <sstream>
#include <iomanip>

void Monitor::onStateChange(const std::string& state,
                             double volumeML,
                             int    bottleCount) {
    std::ostringstream oss;
    oss << std::fixed << std::setprecision(1)
        << "[State: " << state
        << " | Volume: " << volumeML << " ml"
        << " | Bottles: " << bottleCount << "]";
    Logger::info(oss.str());

    if (callback_) {
        callback_(state, volumeML, bottleCount);
    }
}
