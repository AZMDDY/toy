// Copyright (c) 2022 zhengzhibing All rights reserved.
// Description:

#ifndef TOY_ASYNC_H
#define TOY_ASYNC_H
#include <future>

namespace Utility {
// 保证真异步执行任务，结果存在feature
template<typename F, typename Ts>
auto RealAsync(F&& f, Ts&&... params)
{
    return std::async(std::launch::async, std::forward<F>(f), std::forward<Ts>(params)...);
}
}  // namespace Utility
#endif  // TOY_ASYNC_H
