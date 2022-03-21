#include "../common.h"
#include <iostream>
#include <functional>
#include "../tools.hpp"

using namespace std;

class sort_test
{
private:
    /* data */
    std::vector<int> inputVector;
    //std::vector<int> inputVector={22,11,55,22,66,99,1,3, 2,8,4,2,6,7,12,8};
    //std::vector<int> inputVector={1,3,2,8,4,2};
    //std::vector<int> inputVector={1,3,6,8,4,5};
    //std::vector<int> inputVector={1,3,2,8,4,2,9,7};
public:
    sort_test(/* args */);
    ~sort_test();

    /*
    插入排序
    */
    void insert_sort(){
        for(int i=0; i<(int)inputVector.size(); i++){
            for(int j=i; j>0; j--){
                if(inputVector[j] < inputVector[j-1]){
                    int tmp = inputVector[j];
                    inputVector[j] = inputVector[j-1];
                    inputVector[j-1] = tmp;
                }
            }
        }
    }
    /*
    * 希尔排序
    *
    * 参数说明：
    *     a -- 待排序的数组
    *     n -- 数组的长度
    */
    void shell_sort1(std::vector<int> &a, int n)
    {
        int i,j,gap;

        // gap为步长，每次减为原来的一半。
        for (gap = n / 2; gap > 0; gap /= 2)
        {
            // 共gap个组，对每一组都执行直接插入排序
            for (i = 0 ;i < gap; i++)
            {
                for (j = i + gap; j < n; j += gap) 
                {
                    // 如果a[j] < a[j-gap]，则寻找a[j]位置，并将后面数据的位置都后移。
                    if (a[j] < a[j - gap])
                    {
                        int tmp = a[j];
                        int k = j - gap;
                        while (k >= 0 && a[k] > tmp)
                        {
                            a[k + gap] = a[k];
                            k -= gap;
                        }
                        a[k + gap] = tmp;
                    }
                }
            }

        }
    }
    /*
    * 对希尔排序中的单个组进行排序
    *
    * 参数说明：
    *     a -- 待排序的数组
    *     n -- 数组总的长度
    *     i -- 组的起始位置
    *     gap -- 组的步长
    *
    *  组是"从i开始，将相隔gap长度的数都取出"所组成的！
    */
    void group_sort(std::vector<int> &a, int n, int i,int gap)
    {
        int j;

        for (j = i + gap; j < n; j += gap) 
        {
            // 如果a[j] < a[j-gap]，则寻找a[j]位置，并将后面数据的位置都后移。
            if (a[j] < a[j - gap])
            {
                int tmp = a[j];
                int k = j - gap;
                while (k >= 0 && a[k] > tmp)
                {
                    a[k + gap] = a[k];
                    k -= gap;
                }
                a[k + gap] = tmp;
            }
        }
    }

    /*
    * 希尔排序
    *
    * 参数说明：
    *     a -- 待排序的数组
    *     n -- 数组的长度
    */
    void shell_sort2(std::vector<int> &a, int n)
    {
        int i,gap;

        // gap为步长，每次减为原来的一半。
        for (gap = n / 2; gap > 0; gap /= 2)
        {
            // 共gap个组，对每一组都执行直接插入排序
            for (i = 0 ;i < gap; i++)
                group_sort(a, n, i, gap);
        }
    }

    //二分查找
    int erfen_find(std::vector<int>& v, int target){
        int l = 0;
        int r = v.size() - 1;
        while(l < r){
            int m = l + (r - l)/2;
            if(v[m] == target){
                return m;
            }
            if(target < v[m]){
                r = m - 1;
            }
            else{
                l = m + 1;
            }
        }
        return -1;
    }

    void test(int i, string str){
        cout<<"test "<<i<<" "<<str<<endl;
    }
    void test2(string str){
        cout<<"test "<<str<<endl;
    }

    void insert_sort2(){
        vector<int>& v = inputVector;
        for(size_t i=1; i<v.size(); i++){
            int tmp = v[i];
            for(size_t j=i; j>0; j--){
                if(v[j-1] > tmp) v[j] = v[j-1];
                else{
                    v[j] = tmp;
                    break;;
                }
                if(j == 1){
                    v[0] = tmp;
                }
            }
        }
    }

    void quickSort(vector<int>& v, int left, int right){
        int mid;
        if(left < right){
            mid = part(v, left, right);
            quickSort(v, left, mid-1);
            quickSort(v, mid+1, right);
        }
    }
    int part(vector<int>& v, int left, int right){
        int base = v[left];
        int index = left+1;
        for(int i=left+1; i<=right; i++){
            if(v[i] < base){
                swap(v, i, index++);
            }
        }
        swap(v, left, index-1);
        return index-1;
    }
    void swap(vector<int>& v, int index1, int index2){
        int tmp = v[index1];
        v[index1] = v[index2];
        v[index2] = tmp;
    }

    void createHeap(vector<int>& v, int len){
        for(int i=len/2-1; i>=0; i--){
            heapify(v, i, len);
        }
    }
    void swapHead(vector<int>& v, int len){
        int tmp = v[len-1];
        v[len-1] = v[0];
        v[0] = tmp;
    }
    void heapify(vector<int>& v, int index, int len){
        if(len > index*2+1){
            if(v[index] < v[index*2+1]) swap(v,index,index*2+1);
            heapify(v, index*2+1, len);
        }
        if(len > index*2+2){
            if(v[index] < v[index*2+2]) swap(v,index,index*2+2);
            heapify(v, index*2+2, len);
        }
    }
    void heapSort(vector<int>& v){
        createHeap(v, v.size());
        for(int len=v.size(); len>1; ){
            swapHead(v, len);
            heapify(v,0,--len);
        }
    }

};

sort_test::sort_test(/* args */)
{
    ilog("test sort in");
    inputVector={22,11,55,22,66,99,1,3, 2,8,4,2,6,7,12,8};
    //insert_sort2();
    //auto f = std::bind(&sort_test::insert_sort, this);
    //auto f = std::bind(&sort_test::shell_sort1, this, inputVector, inputVector.size());
    //tools::test_runTime<>(f);
    //shell_sort1(inputVector, inputVector.size());
    //shell_sort2(inputVector, inputVector.size());
    //quickSort(inputVector, 0, inputVector.size()-1);
    heapSort(inputVector);
    cout<<"sort:";
    for(int i=0; i<(int)inputVector.size(); i++){
        cout<<" "<<inputVector[i];
    }
    cout << endl;
    // int res = erfen_find(inputVector, 5);
    // cout << "erfine find resuldt: " << res << endl;

    std::vector<int> vec(0);
    for(int i = 0 ; i < 10; i++)
    {
        vec.push_back(i);
        
    }
    vec.push_back(7);
    auto ret = std::remove(vec.begin(), vec.end(), 7);
    vec.erase(ret, vec.end());

    for(auto &i : vec)
    {
        std::cout << i << " " << std::endl;
    }
}

sort_test::~sort_test()
{
}
