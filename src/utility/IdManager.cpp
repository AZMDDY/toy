// Copyright (c) 2022 zhengzhibing All rights reserved.
// Description:

#include "IdManager.h"
#include "Log.h"
namespace Utility {
IdManager::IdManager(uint32_t idMaxVal) : idFlag(idMaxVal, false), curIdIter(idFlag.begin()) {}

uint32_t IdManager::AllocId()
{
    // 优先分配未被使用的ID
    for (auto iter = curIdIter; iter != idFlag.end(); ++iter) {
        if (!(*iter)) {
            *iter = true;
            ++curIdIter;
            return iter - idFlag.begin();
        }
    }
    // 如果ID都被使用，则使用用被释放过的ID
    for (auto iter = idFlag.begin(); iter != curIdIter; ++iter) {
        if (!(*iter)) {
            *iter = true;
            return iter - idFlag.begin();
        }
    }

    LOG_ERROR() << "id is exhausted";
    return UINT32_MAX;
}

void IdManager::ReleaseId(uint32_t id)
{
    auto iter = idFlag.begin() + id;
    if (!(*iter)) {
        LOG_ERROR() << "the id [" << id << "] not exist.";
        return;
    }
    *iter = false;
}
}  // namespace Utility