// Copyright (c) 2021 zhengzhibing All rights reserved.

#include "map.h"
#include "log.h"
namespace Utility {
Map::Map() : width(0), height(0) {}

Map::Map(int width, int height) : width(width), height(height) {}

bool Map::IsValidPos(const Pos& pos) const
{
    if (pos.x < 0 || pos.y < 0 || pos.x >= width || pos.y >= height) {
        LOG_ERROR() << "the map width: " << width << ", height: " << height << ", pos is out of range. " << pos.ToStr();
        return false;
    }
    return true;
}

bool Map::HaveZone(const Zone& zone) const
{
    if (!IsValidPos(zone.pos)) {
        LOG_ERROR() << "the map does not have " << zone.ToStr();
        return false;
    }
    auto iter = zones.find(zone.pos);
    if (iter == zones.end()) {
        LOG_ERROR() << "zones does not have " << zone.ToStr();
        return false;
    }
    return zones.at(zone.pos) == zone;
}

bool Map::GetZone(const Pos& pos, Zone& zone) const
{
    if (!IsValidPos(pos)) {
        LOG_ERROR() << "the map does not have " << zone.ToStr();
        return false;
    }
    auto iter = zones.find(pos);
    if (iter == zones.end()) {
        LOG_ERROR() << "the zones does not have " << pos.ToStr();
        return false;
    }
    zone = zones.at(pos);
    return true;
}

bool Map::SetZone(const Pos& pos, const Zone& zone)
{
    if (pos != zone.pos) {
        LOG_ERROR() << "the map's pos" << pos.ToStr() << " does not have " << zone.ToStr();
        return false;
    }
    if (zones.find(pos) == zones.end()) {
        LOG_ERROR() << "the zones does not have " << zone.ToStr();
        return false;
    }
    zones[pos] = zone;
    return true;
}

bool Map::Insert(const Zone& zone)
{
    if (!IsValidPos(zone.pos)) {
        LOG_ERROR() << "the map does not have " << zone.ToStr();
        return false;
    }
    zones.insert({zone.pos, zone});
    return true;
}
}  // namespace Utility