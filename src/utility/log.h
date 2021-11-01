// Copyright (c) 2021 zhengzhibing All rights reserved.

#ifndef MYTOY_LOG_H
#define MYTOY_LOG_H
#include <iostream>
#include "base.h"
namespace Utility {

#define LOG_DEBUG() details::LogStream() << "[D: " << __TIME__ << " " << __FILENAME__ << ":" << __LINE__ << "] "
#define LOG_INFO() details::LogStream() << "[I: " << __TIME__ << " " << __FILENAME__ << ":" << __LINE__ << "] "
#define LOG_ERROR() details::LogStream() << "[E: " << __TIME__ << " " << __FILENAME__ << ":" << __LINE__ << "] "

namespace details {
    class LogStream {
    public:
        LogStream() = default;
        LogStream(LogStream&) = delete;
        LogStream& operator=(const LogStream&) = delete;

        template<class T>
        LogStream& operator<<(T value)
        {
            data += std::to_string(value);
            return *this;
        }

        LogStream& operator<<(const std::string& value)
        {
            data += value;
            return *this;
        }

        LogStream& operator<<(const char* value)
        {
            data += value;
            return *this;
        }

        LogStream& operator<<(char* value)
        {
            data += value;
            return *this;
        }

        ~LogStream() { std::cerr << data << std::endl; }

    private:
        std::string data;
    };
}  // namespace details
}  // namespace Utility
#endif  // MYTOY_LOG_H
