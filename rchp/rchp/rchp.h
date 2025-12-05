#ifndef RCHP_H
#define RCHP_H

#pragma pack(push, 1)

#include <string>
#include <exception>

class rchp_error : public std::exception {
public:
    explicit rchp_error(std::string message = "unknown error")
        noexcept
        : message_(std::move(message))
    {}

    const char* what() const noexcept override {
        return message_.c_str();
    }

    std::string message() const {
        return message_;
    }

private:
    std::string message_;
};

#endif
