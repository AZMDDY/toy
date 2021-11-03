// Copyright (c) 2021 zhengzhibing All rights reserved.

#include "map.h"
#include "log.h"
namespace Utility {
Map::Map() : width(0), height(0) {}

Map::Map(int width, int height) : width(width), height(height) {}

bool Map::InRange(const Pos& pos) const
{
    if (pos.x < 0 || pos.y < 0 || pos.x >= width || pos.y >= height) {
        LOG_DEBUG() << "the map width: " << width << ", height: " << height << ", pos is out of range. " << pos.ToStr();
        return false;
    }
    return true;
}

bool Map::HavePos(const Pos& pos) const
{
    if (!InRange(pos)) {
        return false;
    }
    return zones.find(pos) != zones.end();
}

bool Map::HaveZone(const Zone& zone) const
{
    if (!HavePos(zone.pos)) {
        LOG_DEBUG() << "the map does not have " << zone.ToStr();
        return false;
    }
    return zones.at(zone.pos) == zone;
}

bool Map::GetZone(const Pos& pos, Zone& zone) const
{
    if (!HavePos(pos)) {
        LOG_DEBUG() << "the map does not have " << pos.ToStr();
        return false;
    }
    zone = zones.at(pos);
    return true;
}

bool Map::SetZone(const Pos& pos, const Zone& zone)
{
    if (!HavePos(pos)) {
        LOG_DEBUG() << "the map does not have " << zone.ToStr();
        return false;
    }

    if (pos != zone.pos) {
        LOG_DEBUG() << "the map's pos" << pos.ToStr() << " does not have " << zone.ToStr();
        return false;
    }

    zones[pos] = zone;
    return true;
}

bool Map::Insert(const Zone& zone)
{
    if (!InRange(zone.pos)) {
        LOG_DEBUG() << "the map does not have " << zone.ToStr();
        return false;
    }
    zones.insert({zone.pos, zone});
    return true;
}

bool Map::Empty() const
{
    if (width <= 0 && height <= 0) {
        return true;
    }
    return zones.empty();
}
}  // namespace Utility