#pragma once

#include <string>
#include <exception>

namespace pen {
class FailedToInitialize : public std::exception {
public:
    explicit FailedToInitialize(std::string reason);

    const std::string &reason() const noexcept;

    const char *what() const noexcept override;

private:
    const std::string reason_;
};
} // namespace pen
