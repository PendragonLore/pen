#include "FailedToInitialize.hpp"

namespace pen {
FailedToInitialize::FailedToInitialize(std::string reason) : reason_(std::move(reason)) {}

const std::string &FailedToInitialize::reason() const noexcept { return reason_; }

const char *FailedToInitialize::what() const noexcept { return ("Failed to initialize SDL: " + reason_).c_str(); }
} // namespace pen
