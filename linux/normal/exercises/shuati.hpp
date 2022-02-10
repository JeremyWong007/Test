#include <vector>
#include <iostream>
#include "../common.h"

using namespace std;
class shuati
{
private:
    /* data */
public:
    shuati(/* args */);
    ~shuati();

    /*题目：
    最近小明搬到了新家，他正在粉刷墙壁，但是不幸的是他粉刷的墙壁并不理想。他的墙壁是一个长度为 的格子，每个格子用0表示红色，用1表示蓝色。现在墙壁是一个非常混乱的颜色。
    他想将墙壁涂成左边全是蓝色右边全是红色，可以将墙壁刷成全是红色或者蓝色。请问他至少需要粉刷多少个格子墙壁刷成他想要的样子？
    数据范围：1<=n<=10000
    进阶：时间复杂度O(n)，空间复杂度O(n)
    */
    void shuaqiang(){
        //vector<char> q = {1,1,0,0,1,0,1,0,0,1,1,0,0};
        //vector<char> q = {1,1,1,1,1,1,1,1,1,1,1,1,0};
        //vector<char> q = {0,0,0,0,0,0,0,0,0,0,0,0,0};
        //vector<char> q = {1,1,0,0,0,0,0,0,0,1,1,0,0};
        vector<char> q = {0,1,0,0,0,0,0,0,0,1,1,0,0};
        int c_blue=0;
        char b=1;
        int c_min=0;
        int c_red=0;
        for(int i=0; i<q.size(); i++){
            if(q[i] == 1){
                c_red++;
            }
        }
        c_min=c_red;

        for(int i=0; i<q.size(); i++){
            if(q[i] != b){
                if(q[i] == 0){
                    if(c_blue+c_red < c_min){
                        c_min = c_blue+c_red;
                    }
                    cout<<"i="<<i<<endl;
                    cout<<"min="<<c_min<<endl;
                    cout<<"c_blue="<<c_blue<<" c_red="<<c_red<<endl;
                }
            }
            if(q[i] == 0){
                c_blue++;
            }
            else{
                c_red--;
            }
            b = q[i];
        }
    }
};

shuati::shuati(/* args */)
{
    ilog("shuati test in");
    shuaqiang();
}

shuati::~shuati()
{
}
