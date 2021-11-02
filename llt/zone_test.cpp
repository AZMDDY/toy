// Copyright (c) 2021 zhengzhibing All rights reserved.
#include "gtest/gtest.h"
#include "log.h"
#include "zone.h"
using namespace Utility;
class ZoneFixture : public ::testing::Test {
protected:
    void SetUp() override {}
    void TearDown() override {}

protected:
    bool ret = false;
};

TEST_F(ZoneFixture, ZoneTest)
{
    Zone z1({0, 0}, {});
    LOG_INFO() << z1.ToStr();
    z1.AddUnit(1);
    z1.AddUnit(2);
    z1.AddUnit(3);
    ASSERT_EQ(z1.HaveUnit(1), true);
    ASSERT_EQ(z1.HaveUnit(5), false);
    z1.RmvUnits(1);
    ASSERT_EQ(z1.HaveUnit(1), false);
    ASSERT_EQ(z1 == Zone({0, 0}, {2, 3}), true);
    ASSERT_EQ(z1 == Zone({0, 1}, {1, 3}), false);
    ASSERT_EQ(z1 == Zone({0, 0}, {1, 0}), false);
}

TEST_F(ZoneFixture, ZoneTypeTest)
{
    Zone z1({0, 0}, {1, 2, 3, 4, 5, 5, 3, 4});
    ASSERT_EQ(z1.GetUnitTypes() == std::vector<int32_t>({1, 2, 3, 4, 5}), true);
    ASSERT_EQ(z1.GetUnitTypes() == std::vector<int32_t>({1, 2, 3, 4}), false);
    ASSERT_EQ(z1.RepeatUnits() == std::vector<int32_t>({3, 4, 5}), true);
    ASSERT_EQ(z1.RepeatUnits() == std::vector<int32_t>({3, 4}), false);
}

TEST_F(ZoneFixture, RmvUnitTest)
{
    Zone z1({0, 0}, {1, 2, 3, 4, 5, 5, 3, 4});

    ret = z1.RmvUnits(1);
    ASSERT_EQ(ret, true);
    ret = z1.RmvUnits(1);
    ASSERT_EQ(ret, false);
    ret = z1.RmvUnits(4);
    ASSERT_EQ(ret, true);
    ret = z1.HaveUnit(4);
    ASSERT_EQ(ret, false);
    ret = z1.RmvOneUnit(3);
    ASSERT_EQ(ret, true);
    ret = z1.RmvOneUnit(3);
    ASSERT_EQ(ret, true);
    ret = z1.RmvOneUnit(3);
    ASSERT_EQ(ret, false);
}
