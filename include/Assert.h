//
// Created by siyualbak on 19. 3. 16.
//

#ifndef ASSERT_ASSERT_H
#define ASSERT_ASSERT_H

#include <string>
#include <sstream>
#include <iostream>
#include <stdexcept>

namespace Assert {
enum class Mode {
  throw_, terminate_, ignore_
};

constexpr Mode currentMode = ASSERT_CURRENT_MODE;
constexpr int currentLevel = ASSERT_CURRENT_LEVEL;
constexpr int defaultLevel = ASSERT_DEFAULT_LEVEL;

constexpr bool level(int n) {
  return n <= currentLevel;
}

struct Error : std::runtime_error {
  explicit Error(const std::string &message)
    : std::runtime_error{message} {}
};

std::string compose(const char *file, int line, const std::string &message) {
  std::ostringstream stringStream{};
  stringStream << "Assertion failed (" << file << ", " << line << "): " << message;

  return stringStream.str();
}

template<bool condition = level(defaultLevel), typename Except = Error>
void dynamic(bool assertion, const std::string &message = "Assert::danamic failed") {
  if (assertion)
    return;
  if (currentMode == Mode::throw_)
    throw Except{message};
  if (currentMode == Mode::terminate_)
    std::terminate();
}

template<>
void dynamic<false, Error>(bool, const std::string &) {
}
void dynamic(bool assertion, const std::string &message) {
  dynamic<true, Error>(assertion, message);
}
void dynamic(bool assertion) {
  dynamic<true, Error>(assertion);
}

}

#endif //ASSERT_ASSERT_H
