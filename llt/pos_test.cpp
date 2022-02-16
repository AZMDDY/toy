// Copyright (c) 2021 zhengzhibing All rights reserved.
#include "gtest/gtest.h"
#include "Log.h"
#include "Pos.h"
using namespace Utility;
class PosFixture : public ::testing::Test {
protected:
    void SetUp() override { SetLogLevel(LogLevel::DEBUG); }
    void TearDown() override {}
};

TEST_F(PosFixture, PosOperator)
{
    Pos p1(1, 1);
    Pos p2(1, 2);
    ASSERT_EQ(p1 + p2, Pos(2, 3));
    p1 += Pos(10, 10);
    ASSERT_EQ(p1, Pos(11, 11));
    ASSERT_EQ(p1 == p2, false);
    ASSERT_EQ(p1 != p2, true);
    ASSERT_EQ(p2.ToStr(), "(1,2)");
    LOG_INFO() << "p2: " << p2.ToStr();
    ASSERT_EQ(p2 * 2, Pos(2, 4));
    ASSERT_EQ(p1 - Pos(3, 3), Pos(8, 8));
    p1 -= Pos(1, 1);
    LOG_INFO() << "p1: " << p1.ToStr();
    ASSERT_EQ(p1, Pos(10, 10));
    auto p3 = p1 + p2;
    LOG_INFO() << "p3: " << p3.ToStr();
}