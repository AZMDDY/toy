// Copyright (c) 2021 zhengzhibing All rights reserved.

#ifndef TOY_POS_H
#define TOY_POS_H
#include <cstdint>
#include <string>
#include <vector>
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

static const std::vector<Pos> DIRECTION({{0, 1}, {1, 0}, {0, -1}, {-1, 0}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}});

}  // namespace Utility
#endif  // TOY_POS_H
