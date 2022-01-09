// Copyright (c) 2021 zhengzhibing All rights reserved.
// Description:

#ifndef TOY_UTILITY_H
#define TOY_UTILITY_H

// 获得C风格数组的大小
template<typename T, std::size_t N>
constexpr std::size_t ArraySize(T (&)[N]) noexcept
{
    return N;
}

// 将枚举值转换成底层整型类型
template<typename E>
constexpr auto Enum2Int(E enumerator) noexcept
{
    return static_cast<std::underlying_type_t<E>>(enumerator);
}

#endif  // TOY_UTILITY_H
