// Copyright (c) 2021 zhengzhibing All rights reserved.

#ifndef TOY_MAP_H
#define TOY_MAP_H
#include <map>
#include "zone.h"
namespace Utility {
class Map {
public:
    Map();
    Map(int width, int height);
    ~Map() = default;
    bool InRange(const Pos& pos) const;
    bool HavePos(const Pos& pos) const;
    bool HaveZone(const Zone& zone) const;
    bool GetZone(const Pos& pos, Zone& zone) const;
    bool SetZone(const Pos& pos, const Zone& zone);
    bool Insert(const Zone& zone);

    bool Empty() const;
public:
    std::map<Pos, Zone> zones;
    int32_t width;
    int32_t height;
};
}  // namespace Utility
#endif  // TOY_MAP_H
