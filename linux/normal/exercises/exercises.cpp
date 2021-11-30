#include <iostream>
#include "../common.h"

using namespace std;

class solution{
    public:
    void moverZero(vector<int> &v){
        int i=0,j=0,k=0;
        for(;i<v.size();i++){
            if(v[i]){
                v[k++]=v[i];
            }
        }
        for(j=k;j<v.size();j++){
            v[j]=0;
        }
    }
    
    void mov(vector<int> &v, int pos){
        for(int i=pos;i<v.size();i++){
            v[i]=v[i+1];
        }
    }
    int deleteDuplicates(vector<int> &v){
        int len=v.size();
        for(int i=0;i<len;i++){
            for(int j=i;j<len;j++){
                for(int k=j+1;k<len;k++){
                    if(v[j]==v[k]){
                        mov(v,k);
                        len--;
                    }
                }
            }
        }
    }
    int removeDuplicates(vector<int> &nums) {
        int k = 0;
        if (nums.size() == 0) return 0;
        for (int i = 1; i < nums.size(); ++i)
            if (nums[i] != nums[k])
                nums[++k] = nums[i];
        return k + 1;
    }
};

int exercises(){
    std::cout<<"****************************************************************************************************************************************"<<std::endl;
    ilog("exercises in");
    vector<int> v{0,0,3,1,1,3,1,3,3,2,2,4};
    cout<<v[0]<<v[1]<<v[2]<<v[3]<<v[4]<<endl;
    solution a;
    //a.moverZero(v);
    //cout<<v[0]<<v[1]<<v[2]<<v[3]<<endl;
    //int len=a.deleteDuplicates(v);
    int len=a.removeDuplicates(v);
    cout<<"len="<<len<<endl;
    cout<<v[0]<<v[1]<<v[2]<<v[3]<<v[4]<<endl;
    return 0;
}