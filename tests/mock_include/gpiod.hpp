/**
 * @file gpiod.hpp (MOCK)
 * @brief Mock libgpiod v1 C++ header for Windows/WSL testing without GPIO hardware.
 */

#ifndef GPIOD_HPP_MOCK
#define GPIOD_HPP_MOCK

#include <chrono>
#include <cstddef>
#include <cstdint>
#include <iostream>
#include <string>
#include <thread>

namespace gpiod {

class line_request {
public:
  static constexpr int DIRECTION_OUTPUT = 1;
  static constexpr int EVENT_FALLING_EDGE = 2;
  static constexpr int FLAG_BIAS_PULL_UP = 4;

  int request_type = 0;
  std::string consumer;
  int flags = 0;
};

struct line_event {
  static constexpr int RISING_EDGE = 1;
  static constexpr int FALLING_EDGE = 2;

  std::chrono::nanoseconds timestamp;
  int event_type = FALLING_EDGE;
};

class line {
public:
  line() = default;

  void request(const line_request &config, int default_val = 0) {
    req_ = config;
    val_ = default_val;
  }

  void set_value(int val) { val_ = val; }

  int get_value() const { return val_; }

  bool event_wait(std::chrono::milliseconds timeout) {
    (void)timeout;
    if (req_.request_type == line_request::EVENT_FALLING_EDGE) {
      std::this_thread::sleep_for(std::chrono::milliseconds(100));
      return true;
    }
    return false;
  }

  line_event event_read() {
    line_event ev;
    auto now = std::chrono::steady_clock::now();
    ev.timestamp = std::chrono::duration_cast<std::chrono::nanoseconds>(
        now.time_since_epoch());
    return ev;
  }

  explicit operator bool() const { return true; }

private:
  line_request req_;
  int val_ = 0;
};

class chip {
public:
  explicit chip(const std::string &path) {
    std::cout << "  [MOCK] Opened GPIO chip: " << path << "\n";
  }

  line get_line(unsigned int offset) {
    (void)offset;
    return line();
  }
};

} // namespace gpiod

#endif // GPIOD_HPP_MOCK
