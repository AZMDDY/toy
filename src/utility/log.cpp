// Copyright (c) 2021 zhengzhibing All rights reserved.
// Description:

#include "Log.h"
namespace Utility {
LogLevel g_logLevel = LogLevel::ERROR;

void SetLogLevel(LogLevel logLevel)
{
    g_logLevel = logLevel;
}

namespace details {
    LogStream::LogStream(LogLevel logLevel) : logLevel(logLevel) {}

    LogStream::~LogStream()
    {
        if (logLevel >= g_logLevel) {
            std::cerr << data << std::endl;
        }
    }

    LogStream& LogStream::operator<<(const std::string& value)
    {
        data += value;
        return *this;
    }

    LogStream& LogStream::operator<<(const char* value)
    {
        data += value;
        return *this;
    }

    LogStream& LogStream::operator<<(char* value)
    {
        data += value;
        return *this;
    }
}  // namespace details
}  // namespace Utility