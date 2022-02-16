// Copyright (c) 2021 zhengzhibing All rights reserved.

#ifndef TOY_ZONE_H
#define TOY_ZONE_H
#include <string>
#include <vector>
#include <set>
#include "Pos.h"
namespace Utility {
class Zone {
public:
    Zone() noexcept = default;
    Zone(const Pos& pos, std::multiset<int32_t> units);
    ~Zone() = default;

    bool operator==(const Zone& zone) const;
    bool operator!=(const Zone& zone) const { return !(*this == zone); }

    bool HaveUnit(int32_t unit) const;
    void AddUnit(int32_t unit);
    bool RmvUnits(int32_t unit);
    bool RmvOneUnit(int32_t unit);
    uint32_t Count() const;
    void Clear();

    std::vector<int32_t> RepeatUnits() const;
    std::vector<int32_t> GetUnitTypes() const;

    std::string ToStr() const;

public:
    Pos pos;
    std::multiset<int32_t> units;  // unit:0 表示空格
};

const static Zone INVALID_ZONE = {};
const static int32_t INVALID_UINT = INT32_MAX;
}  // namespace Utility
#endif  // TOY_ZONE_H
