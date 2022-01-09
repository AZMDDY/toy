// Copyright (c) 2022 zhengzhibing All rights reserved.
// Description:

#ifndef TOY_LEXICAL_CAST_H
#define TOY_LEXICAL_CAST_H
#include <cstdlib>
#include <cstring>
#include <stdexcept>
#include <string>
#include <type_traits>

namespace Utility {
namespace LexicalCastDetail {
    template<typename DestType, typename SrcType>
    struct Converter {
    };

    // to int
    template<typename SrcType>
    struct Converter<int, SrcType> {
        static int Convert(const SrcType& src) { return std::stoi(src); }
    };

    // to long
    template<typename SrcType>
    struct Converter<long, SrcType> {
        static long Convert(const SrcType& src) { return std::stol(src); }
    };

    // to unsigned long
    template<typename SrcType>
    struct Converter<unsigned long, SrcType> {
        static unsigned long Convert(const SrcType& src) { return std::stoul(src, nullptr, 0); }
    };

    // to long long
    template<typename SrcType>
    struct Converter<long long, SrcType> {
        static long long Convert(const SrcType& src) { return std::stoll(src, nullptr, 0); }
    };

    // to unsigned long long
    template<typename SrcType>
    struct Converter<unsigned long long, SrcType> {
        static unsigned long long Convert(const SrcType& src) { return std::stoull(src, nullptr, 0); }
    };

    // to double
    template<typename SrcType>
    struct Converter<double, SrcType> {
        static double Convert(const SrcType& src) { return std::stod(src); }
    };

    // to float
    template<typename SrcType>
    struct Converter<float, SrcType> {
        static float Convert(const SrcType& src) { return std::stof(src); }
    };

    // to long doulbe
    template<typename SrcType>
    struct Converter<long double, SrcType> {
        static long double Convert(const SrcType& src) { return std::stold(src); }
    };

    // to bool
    template<typename SrcType>
    struct Converter<bool, SrcType> {
        static typename std::enable_if<std::is_integral<SrcType>::value, bool>::type Convert(SrcType src)
        {
            return !(!(src));
        }
    };

    // to bool
    template<>
    struct Converter<bool, std::string> {
        static bool Convert(const std::string& src)
        {
            if (src == "true" || src == "True") {
                return true;
            }
            if (src == "false" || src == "False") {
                return false;
            }
            throw std::invalid_argument("argument is invalid");
        }
    };

    // to bool
    template<>
    struct Converter<bool, const char*> {
        static bool Convert(const char* src, size_t len)
        {
            std::string str(src, strnlen(src, len));
            return Converter<bool, std::string>::Convert(str);
        }
    };

    // to bool
    template<unsigned N>
    struct Converter<bool, char[N]> {
        static bool Convert(const char (&src)[N])
        {
            std::string str(src, strnlen(src, N));
            return Converter<bool, std::string>::Convert(str);
        }
    };

    // to string
    template<typename SrcType>
    struct Converter<std::string, SrcType> {
        static std::string Convert(const SrcType& src) { return std::to_string(src); }
    };

    // to string
    template<unsigned N>
    struct Converter<std::string, char[N]> {
        static std::string Convert(const char (&src)[N]) { return {src, strnlen(src, N)}; }
    };

    // to string
    template<>
    struct Converter<std::string, bool> {
        static std::string Convert(bool src)
        {
            if (src) {
                return "true";
            }
            return "false";
        }
    };
}  // namespace LexicalCastDetail

template<typename DestType, typename SrcType>
typename std::enable_if<!std::is_same<DestType, SrcType>::value, DestType>::type LexicalCast(const SrcType& src)
{
    return LexicalCastDetail::Converter<DestType, SrcType>::Convert(src);
}

template<typename DestType, typename SrcType>
typename std::enable_if<std::is_same<DestType, SrcType>::value, DestType>::type LexicalCast(const SrcType& src)
{
    return src;
}
}  // namespace Utility
#endif  // TOY_LEXICAL_CAST_H
