// Copyright (c) 2021 zhengzhibing All rights reserved.
// Description:

#include <map>
#include "gtest/gtest.h"
#include "log.h"
#include "pos_cost.h"
using namespace std;
using namespace Utility;
using namespace Algorithm;
class PosCostFixture : public ::testing::Test {
protected:
    void SetUp() override { SetLogLevel(LogLevel::DEBUG); }
    void TearDown() override {}
};

TEST_F(PosCostFixture, SortPostCost)
{
    map<PosCost, int32_t> posCostMap;
    posCostMap.insert({{Pos(1, 1), 3}, 3});
    posCostMap.insert({{Pos(1, 2), 1}, 1});
    posCostMap.insert({{Pos(1, 3), 2}, 1});

    for (auto& postCost : posCostMap) {
        LOG_INFO() << postCost.first.ToStr();
    }
    LOG_INFO() << posCostMap.begin()->first.ToStr();
}