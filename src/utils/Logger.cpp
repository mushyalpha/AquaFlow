#include "utils/Logger.h"

std::mutex Logger::mutex_;

void Logger::info(const std::string& msg) {
    std::lock_guard<std::mutex> lock(mutex_);
    std::cout << "[INFO]  " << msg << "\n";
}

void Logger::warn(const std::string& msg) {
    std::lock_guard<std::mutex> lock(mutex_);
    std::cout << "[WARN]  " << msg << "\n";
}

void Logger::error(const std::string& msg) {
    std::lock_guard<std::mutex> lock(mutex_);
    std::cerr << "[ERROR] " << msg << "\n";
}
