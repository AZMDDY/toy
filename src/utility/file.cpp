// Copyright (c) 2021 zhengzhibing All rights reserved.

#include "File.h"
#include <fstream>
#include "Log.h"
namespace Utility {
using namespace std;
bool ReadFile(const string& fileName, string& content)
{
    ifstream ifs(fileName, std::ios::binary);
    if (!ifs.good()) {
        LOG_ERROR() << "open file failed. file name: " << fileName;
        return false;
    }
    string str((istreambuf_iterator<char>(ifs)), istreambuf_iterator<char>());
    content = str;
    return true;
}

bool WriteFile(const string& fileName, const string& content)
{
    ofstream ofs(fileName, std::ios::binary | std::ios::out | std::ios::trunc);
    if (!ofs.good()) {
        LOG_ERROR() << "open file failed. file name: " << fileName;
        return false;
    }
    ofs.write(content.c_str(), static_cast<long>(content.size()));
    return true;
}
}  // namespace Utility
