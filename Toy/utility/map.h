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
    inline int32_t GetWidth() { return width; }
    inline int32_t GetHeight() { return height; }
    bool IsValidPos(const Pos& pos) const;
    bool HaveZone(const Zone& zone) const;
    bool GetZone(const Pos& pos, Zone& zone) const;
    bool Insert(const Zone& zone);

private:
    int32_t width;
    int32_t height;
    std::map<Pos, Zone> zones;
};
}  // namespace Utility
#endif  // MYTOY_MAP_H
