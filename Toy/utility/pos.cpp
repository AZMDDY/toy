// Copyright (c) 2021 zhengzhibing All rights reserved.

#include "pos.h"
#include <sstream>
namespace Utility {
using namespace std;
Pos::Pos() : x(INT32_MAX), y(INT32_MAX) {}

Pos::Pos(int32_t x, int32_t y) : x(x), y(y) {}

Pos::Pos(const Pos& pos)
{
    this->x = pos.x;
    this->y = pos.y;
}

void Pos::operator+=(const Pos& pos)
{
    this->x += pos.x;
    this->y += pos.y;
}

void Pos::operator-=(const Pos& pos)
{
    this->x -= pos.x;
    this->y -= pos.y;
}

Pos Pos::operator+(const Pos& pos) const
{
    return {this->x + pos.x, this->y + pos.y};
}

Pos Pos::operator-(const Pos& pos) const
{
    return {this->x - pos.x, this->y - pos.y};
}

Pos Pos::operator*(int32_t ratio) const
{
    return {this->x * ratio, this->y * ratio};
}

bool Pos::operator==(const Pos& pos) const
{
    return this->x == pos.x && this->y == pos.y;
}

bool Pos::operator!=(const Pos& pos) const
{
    return !(*this == pos);
}

std::string Pos::ToStr() const
{
    stringstream ss;
    ss << "(" << x << "," << y << ")";
    return ss.str();
}
bool Pos::operator<(const Pos& pos) const
{
    return this->x < pos.x && this->y < pos.y;
}
}  // namespace Utility