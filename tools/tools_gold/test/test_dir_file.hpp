#include <iostream>
#include <vector>
#include <dirent.h>

using namespace std;
const string default_confPath = "../config/";

class test_dir_file
{
private:
    /* data */
    vector<string> configs;

public:
    test_dir_file(/* args */);
    ~test_dir_file();
    int find_dir_file(const char *dir_name, vector<string> &v);
    bool scanDir();
};

test_dir_file::test_dir_file(/* args */)
{
    cout << "test_dir_file in" << endl;
    scanDir();
}

test_dir_file::~test_dir_file()
{
}

// 扫描目录
bool test_dir_file::scanDir() {
    find_dir_file(default_confPath.c_str(), configs);
    // 加载内容和解析dpname
    // for (auto iter = configs.begin();iter!= configs.end();iter++) {
    //     string cfgTmp = (*iter);
    //     if (!strContains(cfgTmp, ".json") || strContains(cfgTmp, "config.json")) {
    //         continue;
    //     }
    //     auto fileC = policyFileState::instance()->getPolicyFileContentByName(cfgTmp);
    //     if (fileC!="") {
    //         policyFileState::instance()->extractDisplayNameByFileContent(cfgTmp,fileC);
    //     }
    // }
    return true;
}

int test_dir_file::find_dir_file(const char *dir_name, vector<string> &v) {
    DIR *dirp;
    struct dirent *dp;
    dirp = opendir(dir_name);
    while ((dp = readdir(dirp)) != NULL) {
        v.push_back(std::string(default_confPath + dp->d_name));
        cout << std::string(default_confPath + dp->d_name) << endl;
    }
    (void) closedir(dirp);
    return 0;
}
