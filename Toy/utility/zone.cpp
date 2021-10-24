// Copyright (c) 2021 zhengzhibing All rights reserved.

#include "zone.h"
namespace Utility {
Zone::Zone(const Pos& pos, const std::multiset<int32_t>& units) : pos(pos), units(units) {}

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

bool Zone::RmvUnit(int32_t unit)
{
    if (!HaveUnit(unit)) {
        return false;
    }
    units.erase(unit);
    return true;
}
}  // namespace Utility