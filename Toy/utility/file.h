// Copyright (c) 2021 zhengzhibing All rights reserved.

#ifndef MYTOY_FILE_H
#define MYTOY_FILE_H
#include <string>
namespace Utility {
bool ReadFile(const std::string& fileName, std::string& content);

bool WriteFile(const std::string& fileName, const std::string& content);
}  // namespace Utility
#endif  // MYTOY_FILE_H
