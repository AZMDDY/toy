// Copyright (c) 2021 zhengzhibing All rights reserved.

#include "astar.h"
#include <algorithm>
#include "log.h"
namespace Algorithm {
using namespace Utility;

AStar::AStar() : moveType(MoveType::D8) {}

AStar::AStar(MoveType moveType) : moveType(moveType) {}

size_t AStar::FindPath(const Map& map, const Pos& startPos, const Pos& endPos, std::vector<Utility::Pos>& path)
{
    if (map.Empty()) {
        LOG_ERROR() << "the map is empty";
    }
    if (!map.InRange(startPos) || !map.InRange(endPos)) {
        LOG_ERROR() << startPos.ToStr() << " or " << endPos.ToStr() << "is invalid";
        return 0;
    }
    if (startPos == endPos) {
        path.push_back(startPos);
        LOG_DEBUG() << "startPos is equal to endPos. " << startPos.ToStr();
        return path.size();
    }

    OpenZoneEmplace({startPos, 0, nullptr});
    int32_t step = 0;
    while (!openZone.empty()) {
        auto tmpPosCost = OpenZoneTop();
        OpenZonePop();

        if (tmpPosCost.pos == endPos) {
            path.push_back(tmpPosCost.pos);
            // 回溯
            auto parentPosCost = tmpPosCost.parent;
            while (parentPosCost != nullptr) {
                path.push_back(parentPosCost->pos);
                parentPosCost = parentPosCost->parent;
            }
            break;
        } else {
            closeZone[tmpPosCost.pos] = tmpPosCost.cost;
            MigratePoint(map, tmpPosCost, step, startPos, endPos);
        }
    }
    std::reverse(path.begin(), path.end());
    return path.size();
}

bool AStar::PosIsValid(const Map& map, int32_t step, const Pos& pos) const
{
    UNUSED(step);
    Zone zone;
    if (!map.GetZone(pos, zone)) {
        return false;
    }
    // unit: 0 表示空格
    if (!zone.HaveUnit(0)) {
        return false;
    }
    return true;
}

int32_t AStar::MoveCost(const Pos& pos1, const Pos& pos2) const
{
    static const int32_t horCost = 1;
    static const int32_t verCost = 1;
    static const int32_t diaCost = 1;

    int32_t dx = std::abs(pos1.x - pos2.x);
    int32_t dy = std::abs(pos1.y - pos2.y);
    int32_t cost = 0;
    if (moveType == MoveType::D4) {
        cost = dx * horCost + dy * verCost;
    } else if (moveType == MoveType::D8) {
        if (dx > dy) {
            cost = horCost * (dx - dy) + diaCost * dy;
        } else {
            cost = verCost * (dy - dx) + diaCost * dx;
        }
    }
    return cost;
}

int32_t AStar::StartMoveCost(const Pos& startPos, const Pos& curPos) const
{
    return MoveCost(startPos, curPos);
}

int32_t AStar::EndMoveCost(const Pos& curPos, const Pos& endPos) const
{
    return MoveCost(curPos, endPos);
}

void AStar::MigratePoint(const Map& map, const PosCost& posCost, int32_t step, const Pos& startPos, const Pos& endPos)
{
    static const int move[8][2] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}, {1, -1}, {1, 1}, {-1, 1}, {-1, -1}};
    for (int i = 0; i < static_cast<int>(moveType); i++) {
        auto tmpPos = posCost.pos + Pos(move[i][0], move[i][1]);
        if (PosIsValid(map, step, tmpPos)) {
            if (closeZone.find(tmpPos) != closeZone.end()) {
                continue;
            }

            if (openZoneCopy.find(tmpPos) != openZoneCopy.end()) {
                continue;
            }

            int32_t cost = posCost.cost + StartMoveCost(startPos, tmpPos) + EndMoveCost(tmpPos, endPos);
            OpenZoneEmplace({tmpPos, cost, std::make_shared<PosCost>(posCost)});
        }
    }
}

void AStar::OpenZoneEmplace(const PosCost& posCost)
{
    openZone.emplace(posCost, posCost.cost);
    openZoneCopy.emplace(posCost.pos);
}

PosCost AStar::OpenZoneTop() const
{
    if (openZone.empty()) {
        return {};
    }
    return openZone.begin()->first;
}

void AStar::OpenZonePop()
{
    if (openZone.empty()) {
        return;
    }
    auto iter = openZone.begin();
    openZoneCopy.erase(iter->first.pos);
    openZone.erase(iter);
}
}  // namespace Algorithm