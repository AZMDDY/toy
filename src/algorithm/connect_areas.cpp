// Copyright (c) 2021 zhengzhibing All rights reserved.

#include "connect_areas.h"
namespace Algorithm {
uint32_t ConnectAreas::areasNum = 0;
std::vector<Utility::Pos> ConnectAreas::minArea = {};
std::vector<Utility::Pos> ConnectAreas::maxArea = {};

void Dfs(const std::function<bool(const Utility::Zone&)>& isBlank, Utility::Map& map, const Utility::Pos& pos, std::vector<Utility::Pos>& area)
{
    if (!map.HavePos(pos)) {
        return;
    }
    if (!isBlank(map[pos])) {
        return;
    }

    map[pos].Clear();
    map[pos].AddUnit(Utility::INVALID_UINT);

    area.push_back(pos);
    for(const auto& dir : Utility::DIRECTION) {
        Dfs(isBlank, map, pos + dir, area);
    }
}

void ConnectAreas::Calculate(const Utility::Map& map, const std::function<bool(const Utility::Zone&)>& isBlank)
{
    areasNum = 0;
    minArea.clear();
    maxArea.clear();

    std::vector<Utility::Pos> area;
    Utility::Map myMap = map;
    for (auto& z : myMap.zones) {
        const auto pos = z.first;
        const auto zone = z.second;
        if (isBlank(zone)) {
            areasNum++;
            area.clear();
            Dfs(isBlank, myMap, pos, area);
            if (minArea.size() > area.size()) {
                minArea = area;
            }
            if (maxArea.size() < area.size()) {
                maxArea = area;
            }
        }
    }
}

uint32_t ConnectAreas::GetAreasNum()
{
    return areasNum;
}

uint32_t ConnectAreas::GetMaxArea(std::vector<Utility::Pos>& area)
{
    area = maxArea;
    return maxArea.size();
}

uint32_t ConnectAreas::GetMinArea(std::vector<Utility::Pos>& area)
{
    area = minArea;
    return minArea.size();
}
}  // namespace Algorithm