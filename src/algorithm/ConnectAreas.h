// Copyright (c) 2021 zhengzhibing All rights reserved.
// 关于区域连通算法
// 1. 计算地图上连通区域个数
// 2. 计算地图上最大连通区域
// 3. 计算地图上最小连通区域

#ifndef TOY_CONNECT_AREAS_H
#define TOY_CONNECT_AREAS_H
#include <functional>
#include "Map.h"
namespace Algorithm {
class ConnectAreas {
public:
    static void Calculate(const Utility::Map& map, const std::function<bool(const Utility::Zone&)>& isBlank);

    static uint32_t GetAreasNum();
    static uint32_t GetMaxArea(std::vector<Utility::Pos>& area);
    static uint32_t GetMinArea(std::vector<Utility::Pos>& area);

private:
    static uint32_t areasNum;
    static std::vector<Utility::Pos> maxArea;
    static std::vector<Utility::Pos> minArea;
};
}  // namespace Algorithm
#endif  // TOY_CONNECT_AREAS_H
