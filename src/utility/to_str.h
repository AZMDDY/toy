// Copyright (c) 2022 zhengzhibing All rights reserved.
// Description:

#ifndef TOY_TO_STR_H
#define TOY_TO_STR_H
#include <type_traits>
#include <string>
#include <cstring>
namespace Utility {
template<std::size_t N>
inline std::string ToString(const char (&chr)[N])
{
    return {chr, strnlen(chr, N)};
}

inline std::string ToString(const char* chr, size_t len)
{
    return {chr, strnlen(chr, len)};
}

template<typename T>
inline std::string ToString(T value)
{
    return std::to_string(value);
}
}  // namespace Utility
#endif  // TOY_TO_STR_H
