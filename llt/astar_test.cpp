// Copyright (c) 2021 zhengzhibing All rights reserved.
// Description:

#include "gtest/gtest.h"
#include "Log.h"
#include "Zone.h"
#include "AStar.h"
using namespace Utility;
using namespace Algorithm;
class AStarFixture : public ::testing::Test {
protected:
    void SetUp() override
    {
        SetLogLevel(LogLevel::DEBUG);

        std::vector<std::vector<int32_t>> maze = {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                                                  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                                                  {0, 0, 1, 1, 1, 1, 0, 0, 1, 1, 1, 0},
                                                  {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0},
                                                  {0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0},
                                                  {0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0},
                                                  {0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0},
                                                  {0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0},
                                                  {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0},
                                                  {0, 0, 1, 1, 1, 0, 0, 1, 1, 1, 1, 0},
                                                  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                                                  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};

        map.height = static_cast<int32_t>(maze.size());
        map.width = static_cast<int32_t>(maze[0].size());
        for (int32_t i = 0; i < map.height; i++) {
            for (int32_t j = 0; j < map.width; j++) {
                map.Insert({Pos(i, j), {maze[i][j]}});
            }
        }
    }
    void TearDown() override {}

protected:
    Map map;
    bool ret = false;
};

TEST_F(AStarFixture, BuildMapTest)
{
    ASSERT_EQ(map.zones.size(), 12 * 12);
    for (auto& zone : map.zones) {
        LOG_INFO() << zone.first.ToStr() << zone.second.ToStr();
    }
}

TEST_F(AStarFixture, FindPath1Test)
{
    AStar a;
    std::vector<Pos> path;
    a.FindPath(map, {0, 0}, {11, 11}, path);
    for (auto& pos : path) {
        LOG_INFO() << pos.ToStr();
    }
}