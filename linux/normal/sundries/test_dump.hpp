/*
简单使用说明：
. tools/shelltool/enable_coredump
首先执行以上命令，然后在同一个终端中执行程序触发coredump

使用说明：
执行以下三条命令，然后启动应用。重启后需要重新设置命令。
echo "1" > /proc/sys/kernel/core_uses_pid
echo '/tmp/core_%e.%p' | sudo tee /proc/sys/kernel/core_pattern
ulimit -c unlimited 【打开新的终端时，需要重新设置】
[注意：ubuntu18.04重启后core_uses_pid和core_pattern的配置会丢失]

core后分析：
确认core文件格式： file /tmp/core_test1.11211
命令： gdb ./test1 /tmp/core_test1.11211
test1为执行程序，core_test1.11211为生成的coredump文件。
bt 查看栈信息

设置limits.conf（可省略）：
临时设置： ulimit -c unlimited 
永久设置： vim /etc/security/limits.conf 添加：
root     soft  core unlimited
root     hard  core unlimited
[注意：ubuntu18.04有bug，不能使用通配符“*”，需要用root]
*/

#include "../common.h"

using namespace std;

class test_dump
{
private:
    /* data */
public:
    test_dump(/* args */);
    ~test_dump();
};

void stackLimit(){
    char vv[2048*2048]={0};
	std::cout<<__FILE__<<":"<<std::dec<<__LINE__<<"  "<<__func__<<vv[0]<<std::endl;
    char vv2[2048*2048]={0};
	std::cout<<__FILE__<<":"<<std::dec<<__LINE__<<"  "<<__func__<<vv2[0]<<std::endl;
    char vv3[2048*2048]={0};
	std::cout<<__FILE__<<":"<<std::dec<<__LINE__<<"  "<<__func__<<vv3[0]<<std::endl;
}

void dividZero(){
    std::cout<<"dividZero in"<<std::endl;
    //int c=10;
    //int d=c/0; //will call segmentfault
}

//提示：segfault at 0 ip 000055c924d09d80 sp 00007ffc3fee1f50 error 6 in test1[55c924cf3000+94000]
void writeToAddrZero(){
    std::cout<<"writeToAddrZero in"<<std::endl;
    int *p=0;
    *p=11;
}

void core_test1()
{
    int i = 0;
    //scanf("%d", i); //will call segmentfault
    scanf("%d", &i);
    printf("%d", i);
}


test_dump::test_dump(/* args */)
{
    ilog("test dump in");
    //    char vv[2048*2048]={0};
    //    std::cout<<__FILE__<<":"<<std::dec<<__LINE__<<"  "<<__func__<<std::endl;
    //stackLimit();
    //dividZero();
    //writeToAddrZero();
    //core_test1();
}

test_dump::~test_dump()
{
}
