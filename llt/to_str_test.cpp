// Copyright (c) 2022 zhengzhibing All rights reserved.
// Description:

#include <string>
#include "gtest/gtest.h"
#include "log.h"
#include "to_str.h"
#include "lexical_cast.h"
using namespace std;
using namespace Utility;

class ToStrFixture : public ::testing::Test {
protected:
    void SetUp() override { SetLogLevel(LogLevel::DEBUG); }
    void TearDown() override {}
};

TEST_F(ToStrFixture, chr2str)
{
    char chr1[6] = "hello";
    ASSERT_EQ(ToString(chr1), string("hello"));

    char chr2[5] = {'h', 'e', 'l', 'l', 'o'};
    ASSERT_EQ(ToString(chr2), string("hello"));

    char chr3[1] = {'\0'};
    ASSERT_EQ(ToString(chr3), string(""));

    char *chr4 = nullptr;
    ASSERT_EQ(ToString(chr4, 0), string(""));

    const char chr5[] = "hello";
    ASSERT_EQ(ToString(chr5), string("hello"));

    const char chr6[] = "";
    ASSERT_EQ(ToString(chr6), string(""));

    const char* chr7 = "hello";
    ASSERT_EQ(ToString(chr7, 5), string("hello"));

    const char* chr8 = "hello";
    ASSERT_EQ(ToString(chr8, 6), string("hello"));
}

TEST_F(ToStrFixture, int2str)
{
    int a1 = 10;
    ASSERT_EQ(ToString(a1), string("10"));

    float a2 = 10.122f;
    ASSERT_EQ(ToString(a2), string("10.122000"));

    double a3 = 0.000011223;
    // 精度
    ASSERT_EQ(ToString(a3), string("0.000011"));

    long long a4 = 1232334343434;
    ASSERT_EQ(ToString(a4), string("1232334343434"));

    char a = 10;
    ASSERT_EQ(ToString(a), string("10"));
}