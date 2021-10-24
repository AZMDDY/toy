// Copyright (c) 2021 zhengzhibing All rights reserved.
#include <string>
#include "gtest/gtest.h"
#include "log.h"
#include "file.h"
using namespace std;
using namespace Utility;
class RWFileFixtrue : public ::testing::Test {
protected:
    void SetUp() override {}
    void TearDown() override {}
};

TEST_F(RWFileFixtrue, writefile)
{
    string fileName = "test.txt";
    string content = "1234567890\navcfdfdfg\n中文";
    bool ret = WriteFile(fileName, content);
    ASSERT_EQ(ret, true);
}

TEST_F(RWFileFixtrue, readfile)
{
    string fileName = "test.txt";
    string content;
    bool ret = ReadFile(fileName, content);
    LOG_INFO() << content;
    ASSERT_EQ(ret, true);
    ret = ReadFile("testtt", content);
    ASSERT_EQ(ret, false);
}