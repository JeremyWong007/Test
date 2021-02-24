#include <iostream>

/*
生成libapi.a的命令：
g++ -c api.cpp 
ar cr libapi.a api.o 
*/
void say(void)
{
    std::cout<<"Hello lib!"<<std::endl;
}