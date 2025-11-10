#ifndef RCHP_H
#define RCHP_H

#include <exception>
#include <string>
#include <utility>

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