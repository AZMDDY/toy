// Copyright (c) 2021 zhengzhibing All rights reserved.
// Description:

#include "gtest/gtest.h"
#include "log.h"
#include "astar.h"
using namespace Utility;
class AStarFixture : public ::testing::Test {
protected:
    void SetUp() override
    {
        map.height = 12;
        map.width = 12;
        map.Insert({{0, 0}, {1, 2}});
        map.Insert({{0, 1}, {1, 2, 3}});
        map.Insert({{0, 2}, {1, 2, 2}});
        map.Insert({{0, 3}, {1}});
        map.Insert({{1, 0}, {}});
        map.Insert({{1, 1}, {}});
        map.Insert({{1, 2}, {4}});
        map.Insert({{1, 3}, {1, 2}});
    }
    void TearDown() override {}

protected:
    Map map;
    bool ret = false;
};