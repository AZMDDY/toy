// Copyright (c) 2021 zhengzhibing All rights reserved.

#ifndef MYTOY_ZONE_H
#define MYTOY_ZONE_H
#include <string>
#include <vector>
#include <set>
#include "pos.h"
namespace Utility {
class Zone {
public:
    Zone() = default;
    Zone(const Pos& pos, std::multiset<int32_t>  units);
    ~Zone() = default;

    bool operator==(const Zone& zone) const;
    bool operator!=(const Zone& zone) const { return !(*this == zone); }

    bool HaveUnit(int32_t unit) const;
    void AddUnit(int32_t unit);
    // 会将相同unit都删除掉
    bool RmvUnit(int32_t unit);
    bool RmvOneUnit(int32_t unit);

    std::vector<int32_t> RepeatUnits() const;
    std::vector<int32_t> GetUnitTypes() const;

    std::string ToStr() const;

public:
    Pos pos;
    std::multiset<int32_t> units;
};
}  // namespace Utility
#endif  // MYTOY_ZONE_H
