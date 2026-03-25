#pragma once

#include <string>
#include <mutex>
#include <iostream>

/**
 * @brief Thread-safe console logger.
 *
 * Wraps std::cout with a mutex so that callbacks arriving from
 * multiple threads (sensor thread, flow thread, main thread) do
 * not interleave their output.
 */
class Logger {
public:
    /** @brief Log an informational message. */
    static void info(const std::string& msg);

    /** @brief Log a warning message. */
    static void warn(const std::string& msg);

    /** @brief Log an error message. */
    static void error(const std::string& msg);

private:
    static std::mutex mutex_;
};
