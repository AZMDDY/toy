// Copyright (c) 2021 zhengzhibing All rights reserved.

#ifndef MYTOY_MAP_H
#define MYTOY_MAP_H
#include <map>
#include "zone.h"
namespace Utility {
class Map {
public:
    Map();
    Map(int width, int height);
    ~Map() = default;
    bool IsValidPos(const Pos& pos) const;
    bool HaveZone(const Zone& zone) const;
    bool GetZone(const Pos& pos, Zone& zone) const;
    bool SetZone(const Pos& pos, const Zone& zone);
    bool Insert(const Zone& zone);
public:
    std::map<Pos, Zone> zones;
    int32_t width;
    int32_t height;
};
}  // namespace Utility
#endif  // MYTOY_MAP_H
