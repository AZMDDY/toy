// Copyright (c) 2021 zhengzhibing All rights reserved.

#ifndef TOY_ASTAR_H
#define TOY_ASTAR_H
#include <vector>
#include <map>
#include <set>
#include "Map.h"
#include "PosCost.h"
namespace Algorithm {
enum class MoveType {
    D4 = 4,  // four direction
    D8 = 8   // eight direction
};

class AStar {
public:
    AStar();
    explicit AStar(MoveType moveType);
    AStar(const AStar& aStar) = delete;
    AStar(AStar&& aStar) = delete;
    AStar operator=(const AStar& aStar) = delete;
    AStar& operator=(AStar&& aStar) = delete;
    ~AStar() = default;

    size_t FindPath(const Utility::Map& map,
                    const Utility::Pos& startPos,
                    const Utility::Pos& endPos,
                    std::vector<Utility::Pos>& path);

protected:
    virtual bool PosIsValid(const Utility::Map& map, int32_t step, const Utility::Pos& pos) const;

    // 起点到当前点的代价
    virtual int32_t StartMoveCost(const Utility::Pos& startPos, const Utility::Pos& curPos) const;

    // 当前点到终点的预估代价
    virtual int32_t EndMoveCost(const Utility::Pos& curPos, const Utility::Pos& endPos) const;

    // 通用的移动代价
    virtual int32_t MoveCost(const Utility::Pos& pos1, const Utility::Pos& pos2) const;

private:
    void MigratePoint(const Utility::Map& map,
                      const PosCost& posCost,
                      int32_t step,
                      const Utility::Pos& startPos,
                      const Utility::Pos& endPos);

    void OpenZoneEmplace(const PosCost& posCost);
    PosCost OpenZoneTop() const;
    void OpenZonePop();


private:
    MoveType moveType;
    std::map<PosCost, int32_t> openZone;  // 按照代价从小到大排序
    std::set<Utility::Pos> openZoneCopy;  // 用于快速查找
    std::map<Utility::Pos, int32_t> closeZone;
};
}  // namespace Algorithm
#endif  // TOY_ASTAR_H
