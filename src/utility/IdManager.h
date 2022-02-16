// Copyright (c) 2022 zhengzhibing All rights reserved.
// Description: ID管理，优先分配未被使用的ID

#ifndef TOY_ID_MANAGER_H
#define TOY_ID_MANAGER_H
#include <cstdint>
#include <vector>
namespace Utility {
class IdManager {
public:
    explicit IdManager(uint32_t idMaxVal = UINT32_MAX);
    IdManager(const IdManager&) = default;
    ~IdManager() = default;
    uint32_t AllocId();
    void ReleaseId(uint32_t id);

private:
    std::vector<bool> idFlag;
    std::vector<bool>::iterator curIdIter;
};
}  // namespace Utility
#endif  // TOY_ID_MANAGER_H
