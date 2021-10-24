// Copyright (c) 2021 zhengzhibing All rights reserved.

#ifndef MYTOY_ZONE_H
#define MYTOY_ZONE_H
#include <set>
#include "pos.h"
namespace Utility {
class Zone {
public:
    Zone() = default;
    Zone(const Pos& pos, const std::multiset<int32_t>& units);
    ~Zone() = default;

    bool operator==(const Zone& zone) const;
    bool operator!=(const Zone& zone) const { return !(*this == zone); }

    inline bool HaveUnit(int32_t unit) const;
    inline void AddUnit(int32_t unit);
    inline bool RmvUnit(int32_t unit);

public:
    Pos pos;
    std::multiset<int32_t> units;
};
}  // namespace Utility
#endif  // MYTOY_ZONE_H
