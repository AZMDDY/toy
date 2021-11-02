// Copyright (c) 2021 zhengzhibing All rights reserved.

#ifndef TOY_FILE_H
#define TOY_FILE_H
#include <string>
namespace Utility {
bool ReadFile(const std::string& fileName, std::string& content);

bool WriteFile(const std::string& fileName, const std::string& content);
}  // namespace Utility
#endif  // TOY_FILE_H
