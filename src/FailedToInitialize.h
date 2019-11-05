#ifndef PEN_FAILEDTOINITIALIZE_H
#define PEN_FAILEDTOINITIALIZE_H

#include <exception>

class FailedToInizialize : public std::exception {
public:
    FailedToInizialize(int error_code, const char *error_reason);

    int code() const noexcept;

    const char *reason() const noexcept;

    const char *what() const noexcept override;

private:
    int code_;
    const char *reason_;
};

#endif //PEN_FAILEDTOINITIALIZE_H
