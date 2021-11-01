// Copyright (c) 2021 zhengzhibing All rights reserved.

#include "connect_areas.h"
namespace Algorithm {

uint32_t ConnectAreas::areasNum = 0;
std::vector<Utility::Pos> ConnectAreas::minArea = {};
std::vector<Utility::Pos> ConnectAreas::maxArea = {};

void ConnectAreas::Calculate(const Utility::Map& map, const std::function<bool(const Utility::Zone&)>& isBlank)
{
    areasNum = 0;
    minArea.clear();
    maxArea.clear();

    auto dfs = [](Utility::Map& map, const Utility::Pos& pos) {

    };

    Utility::Map myMap = map;
    for (auto& z : myMap.zones) {
        auto& pos = z.first;
        auto& zone = z.second;
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