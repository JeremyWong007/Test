#include <iostream>

/*
参考：https://blog.csdn.net/fireblue1990/article/details/55808086
生成libapi.so的命令：
g++ api.cpp -fPIC -shared -o libapi.so
make
export LD_LIBRARY_PATH=./
*/
void say(void)
{
    std::cout<<"Hello lib!"<<std::endl;
}