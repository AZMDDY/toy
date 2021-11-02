// Copyright (c) 2021 zhengzhibing All rights reserved.
// Description: astar算法中点的累计代价

#ifndef TOY_POS_COST_H
#define TOY_POS_COST_H
#include <memory>
#include <utility>
#include <string>
#include "pos.h"
namespace Algorithm {
class PosCost;
using PosCostPtr = std::shared_ptr<PosCost>;

class PosCost {
public:
    PosCost() : pos(), cost(0), parent(nullptr) {}

    PosCost(const Utility::Pos& pos, int32_t cost, PosCostPtr parent = nullptr)
        : pos(pos), cost(cost), parent(std::move(parent))
    {
    }
    PosCost(const PosCost& cost) = default;
    ~PosCost() = default;

    bool operator<(const PosCost& posCost) const { return this->cost < posCost.cost; }

    std::string ToStr() const { return pos.ToStr() + ":" + std::to_string(cost); }

public:
    Utility::Pos pos;
    int32_t cost;
    PosCostPtr parent;
};
}  // namespace Algorithm
#endif  // TOY_POS_COST_H
