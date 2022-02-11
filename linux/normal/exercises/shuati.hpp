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

    /*题目：
    有一款游戏，过关的方式是按按钮。
    游戏一共有n关，每一关有a[i]个按钮，其中只有唯一一个按钮是可以通关的，按下其他的按钮游戏就会失败。
    好在这个游戏可以重来，而且由于设计者的疏忽，每一关的通关按钮是不变的，所以你可以记住前几关的按钮，重来时就可以直接通关。
    但是...你的运气似乎用在了其他地方，你使用了最多的按按钮次数才成功通关。
    求这个最多的按按钮次数吧！
    */
    void tongguan(){
        vector<char> gate={3,2,2,8,9,22};
        //方案一：模拟通关过程
        vector<char> gate2(gate);
        int n=0;
        for(int i=0; i<gate2.size(); ){
            if(gate2[i] != 1){
                gate2[i]--;
                i=0;
                n++;
            }
            else{
                n++;
                cout<<"i="<<i<<" n="<<n<<endl;
                i++;
            }
        }
        //方案二：f(i)=f(i-1)+1+(gate[i]-1)*(i+1)
        n=gate[0];
        for(int i=1; i<gate.size(); i++){
            n = n + 1 + (gate[i] - 1)*(i + 1);
        }
        cout<<"plan2: n="<<n<<endl;
    }
};

shuati::shuati(/* args */)
{
    ilog("shuati test in");
    //shuaqiang();
    tongguan();
}

shuati::~shuati()
{
}
