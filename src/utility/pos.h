// Copyright (c) 2021 zhengzhibing All rights reserved.

#ifndef MYTOY_POS_H
#define MYTOY_POS_H
#include <cstdint>
#include <string>
namespace Utility {
class Pos {
public:
    Pos();
    Pos(int32_t x, int32_t y);
    Pos(const Pos& pos);
    ~Pos() = default;
    void operator+=(const Pos& pos);
    void operator-=(const Pos& pos);
    Pos operator+(const Pos& pos) const;
    Pos operator-(const Pos& pos) const;
    Pos operator*(int32_t ratio) const;
    bool operator==(const Pos& pos) const;
    bool operator!=(const Pos& pos) const;
    bool operator<(const Pos& pos) const;
    std::string ToStr() const;

public:
    int32_t x;
    int32_t y;
};

static const Pos INVALID_POS(INT32_MAX, INT32_MAX);

}  // namespace Utility
#endif  // MYTOY_POS_H
