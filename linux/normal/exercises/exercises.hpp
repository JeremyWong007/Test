#include <iostream>
#include <list>
#include "../common.h"
#include "sort_test.hpp"
#include <functional>
#include "../tools.hpp"
#include "test_binary_tree.hpp"
#ifdef LIBSODIUM
     #include "test_vrf.hpp"
#endif

using namespace std;

class solution{
    public:
    void moverZero(vector<int> &v){
        int i=0,j=0,k=0;
        for(;i<(int)v.size();i++){
            if(v[i]){
                v[k++]=v[i];
            }
        }
        for(j=k;j<(int)v.size();j++){
            v[j]=0;
        }
    }
    
    void mov(vector<int> &v, int pos){
        for(int i=pos;i<(int)v.size();i++){
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
        return 0;
    }
    int removeDuplicates(vector<int> &nums) {
        int k = 0;
        if (nums.size() == 0) return 0;
        for (int i = 1; i < (int)nums.size(); ++i)
            if (nums[i] != nums[k])
                nums[++k] = nums[i];
        return k + 1;
    }
    int minVector(vector<int> v, int s){
        int minlen=v.size();
        int sub=0;
        int pos=0;
        bool sucess=false;
        for(int i=0;i<(int)v.size()-1;i++){
            sub=v[i];
            for(int j=i+1;(j<(int)v.size())&&(j-i+1<=minlen);j++){
                sub+=v[j];
                if(sub>=s){
                    sucess=true;
                    int minlenTmp=j-i+1;
                    if(minlenTmp<minlen){
                        minlen=minlenTmp;
                        pos=i;
                    }
                    break;
                }
            }
        }
        cout<<"sucess="<<sucess<<"pos="<<pos<<"len="<<minlen<<endl;
        return sucess;
    }
    int minSubArrayLen(int s, vector<int> &nums) {
        int l = 0, r = -1;
        int ans = nums.size() + 1;
        int sum = 0;
        int pos=0;
        while (l < (int)nums.size()) {
            if (r + 1 < (int)nums.size() && sum < s)
                sum += nums[++r];
            else
                sum -= nums[l++];

            if (sum >= s){
                if(ans>r - l + 1){
                    pos=l;
                }
                ans = min(ans, r - l + 1);
            }
        }
        if (ans == (int)nums.size() + 1)
            return 0;
        cout<<"ans="<<ans<<"pos="<<pos<<"r="<<r<<endl;
        return ans;
    }



    int minVector2(int s, vector<int> v){
        int l = 0,r = -1;
        int sum = 0;
        int minlen = (int)v.size()+1;
        int pos = 0;
        while(l < (int)v.size()){
            if((sum < s)&&(r+1 < (int)v.size())){
                sum += v[++r];
            }
            else{
                sum -= v[l++];
            }
            if(sum >= s){
                int tmplen = r-l+1;
                if(tmplen < minlen){
                    minlen = tmplen;
                    pos = l;
                }
            }
        }
        cout<<"minlen="<<minlen<<"pos="<<pos<<endl;
        return 0;
    }

    void merge(list<int> l1, list<int> l2){
        list<int>::iterator ite=l1.begin();
        l1.insert(l1.end(), numeric_limits<int>::max());
        list<int>::iterator ite2=l2.begin();
        for(; ite!=l1.end(); ite++){
            for(; ite2!=l2.end(); ite2++){
                if(*ite2 <= *ite){
                    l1.insert(ite, *ite2);
                }
                else{
                    break;
                }
            }
        }
        l1.pop_back();
        //l1.erase(l1.end());
        // if(ite2 != l2.end()){
        //     for(;ite2 != l2.end(); ite2++){
        //         l1.insert(l1.end(), *ite2);
        //     }
        // }
        cout<<"show:";
        for(ite=l1.begin(); ite!=l1.end(); ite++){
            cout<<" "<<*ite;
        }
        cout<<endl;
    }
};

class exercises
{
private:
    /* data */
public:
    exercises(/* args */);
    ~exercises();
};

exercises::exercises(/* args */)
{
    std::cout<<"****************************************************************************************************************************************"<<std::endl;
    ilog("exercises in");
    #if 0
    vector<int> v{0,0,3,1,1,3,1,3,2,3,2,4,4};
    cout<<v[0]<<v[1]<<v[2]<<v[3]<<v[4]<<endl;
    solution a;
    //a.moverZero(v);
    //cout<<v[0]<<v[1]<<v[2]<<v[3]<<endl;
    //int len=a.deleteDuplicates(v);
    //int len=a.removeDuplicates(v);
    //cout<<"len="<<len<<endl;
    // bool getmin=a.minVector(v,6);
    // getmin=a.minSubArrayLen(6,v);
    // getmin=a.minVector2(6,v);
    // cout<<v[0]<<v[1]<<v[2]<<v[3]<<v[4]<<endl;
    list<int> l1={1,1,4,6,9};
    list<int> l2={0,3,5,5,7,11,13,14,9999};
    a.merge(l1,l2);
    #endif
    // sort_test testsort;
    // test_binary_tree t_binary_tree;
    #ifdef LIBSODIUM
        test_vrf t_vrf;
    #endif
}

exercises::~exercises()
{
}
