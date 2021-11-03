// Copyright (c) 2021 zhengzhibing All rights reserved.

#ifndef TOY_LOG_H
#define TOY_LOG_H
#include <iostream>
#include "base.h"
namespace Utility {

enum class LogLevel { DEBUG = 0, INFO = 1, ERROR = 2 };

#define LOG_DEBUG() \
    details::LogStream(LogLevel::DEBUG) << "[D: " << __TIME__ << " " << __FILENAME__ << ":" << __LINE__ << "] "
#define LOG_INFO() \
    details::LogStream(LogLevel::INFO) << "[I: " << __TIME__ << " " << __FILENAME__ << ":" << __LINE__ << "] "
#define LOG_ERROR() \
    details::LogStream(LogLevel::ERROR) << "[E: " << __TIME__ << " " << __FILENAME__ << ":" << __LINE__ << "] "

void SetLogLevel(LogLevel logLevel);

namespace details {
    class LogStream {
    public:
        explicit LogStream(LogLevel logLevel);
        LogStream(LogStream&) = delete;
        LogStream& operator=(const LogStream&) = delete;
        ~LogStream();

        template<class T>
        LogStream& operator<<(T value)
        {
            data += std::to_string(value);
            return *this;
        }

        LogStream& operator<<(const std::string& value);
        LogStream& operator<<(const char* value);
        LogStream& operator<<(char* value);

    private:
        std::string data;
        LogLevel logLevel;
    };
}  // namespace details
}  // namespace Utility
#endif  // TOY_LOG_H
