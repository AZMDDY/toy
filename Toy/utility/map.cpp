// Copyright (c) 2021 zhengzhibing All rights reserved.

#include "map.h"
namespace Utility {
Map::Map() : width(0), height(0) {}

Map::Map(int width, int height) : width(width), height(height) {}

bool Map::IsValidPos(const Pos& pos) const
{
    if (pos.x < 0 || pos.y < 0 || pos.x >= width || pos.y >= height) {
        return false;
    }
    return zones.find(pos) != zones.end();
}
bool Map::HaveZone(const Zone& zone) const
{
    if (!IsValidPos(zone.pos)) {
        return false;
    }
    return zones.at(zone.pos) == zone;
}
bool Map::GetZone(const Pos& pos, Zone& zone) const
{
    if (!IsValidPos(pos)) {
        return false;
    }
    zone = zones.at(pos);
    return true;
}
bool Map::Insert(const Zone& zone)
{
    if (!IsValidPos(zone.pos)) {
        return false;
    }
    zones.insert({zone.pos, zone});
    return true;
}
}  // namespace Utility