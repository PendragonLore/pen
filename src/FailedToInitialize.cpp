#include "FailedToInitialize.h"

FailedToInizialize::FailedToInizialize(int error_code, const char *error_reason) : code_(error_code),
                                                                                   reason_(error_reason) {}

int FailedToInizialize::code() const noexcept { return code_; }

const char *FailedToInizialize::reason() const noexcept { return reason_; }

const char *FailedToInizialize::what() const noexcept { return reason(); }