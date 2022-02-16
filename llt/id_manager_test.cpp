// Copyright (c) 2022 zhengzhibing All rights reserved.
// Description:
#include "gtest/gtest.h"
#include "Log.h"
#include "IdManager.h"

using namespace Utility;

class IdManagerFixture : public ::testing::Test {
protected:
    IdManagerFixture() : idManager(20) {}

    void SetUp() override { SetLogLevel(LogLevel::DEBUG); }

    void TearDown() override {}

protected:
    IdManager idManager;
};

TEST_F(IdManagerFixture, AllocId) {
    for (uint32_t i = 0; i < 20; i++) {
        uint32_t id = idManager.AllocId();
        ASSERT_EQ(id, i);
    }
    idManager.ReleaseId(10);
    ASSERT_EQ(idManager.AllocId(), 10);
}

TEST_F(IdManagerFixture, ReleaseId) {
    uint32_t id = idManager.AllocId();  // 0
    idManager.AllocId();                // 1
    idManager.AllocId();                // 2
    idManager.AllocId();                // 3
    idManager.AllocId();                // 4
    idManager.ReleaseId(1222);
    idManager.ReleaseId(1);
    idManager.ReleaseId(3);
    id = idManager.AllocId(); // 5
    ASSERT_EQ(id, 5);
    id = idManager.AllocId(); // 6
    ASSERT_EQ(id, 6);
}