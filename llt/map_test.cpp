// Copyright (c) 2021 zhengzhibing All rights reserved.

#include "gtest/gtest.h"
#include "log.h"
#include "map.h"
using namespace Utility;
class MapFixture : public ::testing::Test {
protected:
    void SetUp() override
    {
        SetLogLevel(LogLevel::DEBUG);
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

TEST_F(MapFixture, ZoneNumTest)
{
    ret = map.Insert(Zone(Pos(1, 1), {1, 2}));
    ASSERT_EQ(ret, true);
    ret = map.Insert(Zone(Pos(1, 1), {1, 2}));
    ASSERT_EQ(ret, true);
    ret = map.Insert(Zone(Pos(1, 1), {1, 1}));
    ASSERT_EQ(ret, true);
    ASSERT_EQ(map.zones.size(), 8);
    ret = map.Insert(Zone(Pos(2, 1), {}));
    ASSERT_EQ(ret, true);
    ASSERT_EQ(map.zones.size(), 9);
    ret = map.Insert(Zone(Pos(map.width + 1, map.height + 1), {2, 2}));
    ASSERT_EQ(ret, false);
    ret = map.Insert(Zone(Pos(-1, -22), {}));
    ASSERT_EQ(ret, false);
}

TEST_F(MapFixture, GetSetTest)
{
    ret = map.HaveZone({{0, 0}, {1, 2}});
    ASSERT_EQ(ret, true);
    ret = map.HaveZone({{0, 0}, {1, 3}});
    ASSERT_EQ(ret, false);
    ret = map.HaveZone({{0, 1}, {1, 2}});
    ASSERT_EQ(ret, false);

    Zone z1;
    ret = map.GetZone({0, 0}, z1);
    ASSERT_EQ(ret, true);
    ASSERT_EQ(z1 == Zone({{0, 0}, {1, 2}}), true);
    ret = map.GetZone({0, 10}, z1);
    ASSERT_EQ(ret, false);

    ret = map.SetZone({0, 0}, {{0, 0}, {1, 1, 1}});
    ASSERT_EQ(ret, true);
    map.GetZone({0, 0}, z1);
    ASSERT_EQ(z1 == Zone({{0, 0}, {1, 1, 1}}), true);

    ret = map.SetZone({10, 0}, {{0, 0}, {1, 1, 1}});
    ASSERT_EQ(ret, false);

    ret = map.SetZone({10, 0}, {{10, 0}, {1, 1, 1}});
    ASSERT_EQ(ret, false);
}

TEST_F(MapFixture, HaveTest)
{
    for (auto& zone : map.zones) {
        LOG_INFO() << zone.first.ToStr() << zone.second.ToStr();
    }

    ret = map.InRange({0, 0});
    ASSERT_EQ(ret, true);
    ret = map.InRange({map.width, map.height});
    ASSERT_EQ(ret, false);
    ret = map.InRange({-1, -1});
    ASSERT_EQ(ret, false);

    ret = map.HavePos({0, 0});
    ASSERT_EQ(ret, true);

    ret = map.HavePos({1, 0});
    ASSERT_EQ(ret, true);

    ret = map.HavePos({2, 0});
    ASSERT_EQ(ret, false);

    ret = map.HavePos({3, 0});
    ASSERT_EQ(ret, false);
}
