// Copyright (c) 2021 zhengzhibing All rights reserved.

#include "zone.h"
#include <sstream>
#include "log.h"

namespace Utility {
Zone::Zone(const Pos& pos, std::multiset<int32_t> units) : pos(pos), units(std::move(units)) {}

bool Zone::operator==(const Zone& zone) const
{
    return this->pos == zone.pos && this->units == zone.units;
}

bool Zone::HaveUnit(int32_t unit) const
{
    return units.find(unit) != units.end();
}

void Zone::AddUnit(int32_t unit)
{
    units.insert(unit);
}

bool Zone::RmvUnits(int32_t unit)
{
    if (!HaveUnit(unit)) {
        LOG_DEBUG() << "the zone does not have unit: " << unit;
        return false;
    }
    units.erase(unit);
    return true;
}

bool Zone::RmvOneUnit(int32_t unit)
{
    auto iter = units.find(unit);
    if (iter == units.end()) {
        LOG_DEBUG() << "the zone does not have unit: " << unit;
        return false;
    }
    units.erase(iter);
    return true;
}

uint32_t Zone::Count() const
{
    return units.size();
}
void Zone::Clear()
{
    units.clear();
}

std::string Zone::ToStr() const
{
    std::stringstream ss;
    ss << "zone: " << pos.ToStr() << " units:";
    for (auto& unit : units) {
        ss << " " << unit;
    }
    return ss.str();
}

std::vector<int32_t> Zone::RepeatUnits() const
{
    auto unitTypes = GetUnitTypes();
    std::vector<int32_t> repeatUnits;
    for (auto& unit : unitTypes) {
        if (units.count(unit) > 1) {
            repeatUnits.push_back(unit);
        }
    }
    return repeatUnits;
}

std::vector<int32_t> Zone::GetUnitTypes() const
{
    std::set<int32_t> noRepeatUnits;
    for (auto& unit : units) {
        noRepeatUnits.insert(unit);
    }
    return {noRepeatUnits.begin(), noRepeatUnits.end()};
}
}  // namespace Utility