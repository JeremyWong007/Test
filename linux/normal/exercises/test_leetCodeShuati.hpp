#include "../common.h"
#include "../tools.hpp"
#include <algorithm>
#include <unordered_map>
#include <map>

using namespace std;

class test_leetCodeShuati
{
private:
    /* data */
public:
    test_leetCodeShuati(/* args */);
    ~test_leetCodeShuati();

    int question2_1_1(vector<int>& v){
        vector<int>::iterator it1=v.begin(),it2=v.begin();
        for(++it1; it1!=v.end(); ){
            for(it2=v.begin(); it2!=it1; ){
                if(*it1 == *it2){
                    it1 = v.erase(it1);
                    it1--;
                    break;
                }
                else{
                    it2++;
                }
            }
            it1++;
        }
        return v.size();
    }
    //优点：不执行erase操作，提升算法效率。
    int question2_1_1_2(vector<int>& v){
        if(v.empty()) return 0;
        int len = 1;
        int j = 0;
        for(uint i=1; i<v.size(); i++){
            for(j=0; j<len; j++){
                if(v[i] == v[j]){
                    break;
                }
            }
            if(j == len){
                v[len]=v[i];
                len++;
            }
        }
        v.resize(len);
        return len;
    }
    int question2_1_1_3(vector<int>& v){
        if(v.empty()) return 0;
        int index = 0;
        for(uint i=1; i<v.size(); i++){
            if(v[index] != v[i]){
                v[++index] = v[i];
            }
        }
        return index + 1;
    }

    int question_2_1_2(vector<int>& v){
        int count=0;
        int index=0;
        for(uint i=1; i<v.size(); i++){
            if(v[index] != v[i]){
                v[++index] = v[i];
                count = 0;
            }
            else{
                count++;
                if(count < 2){
                    v[++index] = v[i];
                }
            }
        }
        return index + 1;
    }
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() <= 2) return nums.size();
        int index = 2;
        for (uint i = 2; i < nums.size(); i++){
            if (nums[i] != nums[index - 2])
                nums[index++] = nums[i];
        }
        return index;
    }

    int question2_1_3(vector<int>& v, int target){
        if(v.empty()) return -1;

        int first = 0, last = v.size();
        int mid = 0;
        while (first != last)
        {
            mid = (first + last) / 2;
            if(v[mid] == target){
                return mid;
            }
            if(v[first] < v[mid]){
                if((v[first] <= target)&&(target < v[mid])){
                    last = mid;
                }
                else{
                    first = mid + 1;
                }
            }
            else{
                if((v[mid] < target)&&(target <= v[last-1])){
                    first = mid + 1;
                }
                else{
                    last = mid;
                }
            }
        }
        return -1;
    }

    int question2_1_6(const vector<int> v){
        std::unordered_map<int, bool> um(v.size());
        int longest = 0;
        for(auto i : v) um[i] = false;
        for(auto i : v){
            if(um[i]) continue;
            int len = 1;
            for(int j=i+1; um.find(j)!=um.end(); j++){
                um[j] = true;
                len++;
            }
            for(int j=i-1; um.find(j)!=um.end(); j--){
                um[j] = true;
                len++;
            }
            longest = max(len, longest);
        }
        return longest;
    }

    std::tuple<int,int> question2_1_7(const vector<int>& v, const int& target){
        unordered_map<int, int> um;
        for(uint i=0; i<v.size(); i++){
            um[v[i]] = i;
        }
        for(auto i : v){
            if(um.find(target - i) != um.end()){
                return std::tuple(um[i]+1, um[target-i]+1);
            }
        }
        return std::tuple(0,0);
    }

    int question2_1_15(const vector<int>& v){
        if(v.empty()) return 0;
        struct container
        {
            int max_l = 0;
            int max_r = 0;
        };
        map<int, container> mc;
        int count = 0;
        int max = 0;
        for (size_t i = 1; i < v.size()-1; i++)
        {
            max = std::max(max, v[i-1]);
            mc[i].max_l = max;
        }
        max = 0;
        for (size_t i = v.size()-2; i >0; i--)
        {
            max = std::max(max, v[i+1]);
            mc[i].max_r = max;
        }
        for (size_t i = 1; i < v.size()-1; i++)
        {
            count += std::max(0, (std::min(mc[i].max_l, mc[i].max_r) - v[i]));
        }
        return count;
    }
    int question2_1_15_method2(const vector<int>& v){
        int max_i = 0;
        for(size_t i=0; i<v.size(); i++){
            if(v[i] > v[max_i]){
                max_i = i;
            }
        }
        int peak = 0;
        int water = 0;
        for (int i = 0; i < max_i; i++)
        {
            if(v[i] > peak) peak = v[i];
            else water += peak - v[i];
        }
        peak = 0;
        for (int i = v.size()-1; i > max_i; i--)
        {
            if(v[i] > peak) peak = v[i];
            else water += peak - v[i];
        }
        return water;
    }

    int question2_1_18(int n){
        int fn_2 = 1;
        int fn_1 = 2;
        int fn = 0;
        for(int i=3; i<=n; i++){
            fn = fn_1 + fn_2;
            fn_2 = fn_1;
            fn_1 = fn;
        }
        return fn;
    }
    
    void question2_1_20(vector<vector<int>>& vv){
        vector<bool> row(vv.size(), false), column(vv[0].size(), false);
        for(size_t i=0; i<vv.size(); i++){
            for(size_t j=0; j<vv[0].size(); j++){
                if(vv[i][j] == 0){
                    row[i] = column[j] = true;
                }
            }
        }
        for(size_t i=0; i<vv.size(); i++){
            if(row[i]){
                for(size_t j=0; j<vv[0].size(); j++){
                    vv[i][j] = 0;
                }
                //fill(&vv[i][0], &vv[i][0]+vv[0].size(), 0);
            }
        }
        for(size_t j=0; j<vv[0].size(); j++){
            if(column[j]){
                for(size_t i=0; i<vv.size(); i++){
                    vv[i][j] = 0;
                }
            }
        }
    }
    
    void question2_1_20_method2(vector<vector<int>>& vv){
        vector<bool> row(vv.size(), false), column(vv[0].size(), false);
        for(size_t i=0; i<vv.size(); i++){
            for(size_t j=0; j<vv[0].size(); j++){
                if(vv[i][j] == 0){
                    row[i] = column[j] = true;
                }
            }
        }
        for(size_t i=0; i<vv.size(); i++){
            if(row[i]){
                for(size_t j=0; j<vv[0].size(); j++){
                    vv[i][j] = 0;
                }
                //fill(&vv[i][0], &vv[i][0]+vv[0].size(), 0);
            }
        }
        for(size_t j=0; j<vv[0].size(); j++){
            if(column[j]){
                for(size_t i=0; i<vv.size(); i++){
                    vv[i][j] = 0;
                }
            }
        }
    }
    
    ListNode* question2_2_1(ListNode* l1, ListNode* l2){
        ListNode* l = nullptr;
        ListNode* l3 = l;
        while(l1 != nullptr){
            if(l3 == nullptr){
                l3 = l = new ListNode(0);
            }
            else{
                if(l3->next == nullptr){
                    l3->next = new ListNode(0);
                }
                l3 = l3->next;
            }

            if(l2 != nullptr){
                l3->val += l1->val + l2->val;
                if(l3->val >= 10){
                    l3->val %= 10;
                    l3->next = new ListNode(1);
                }
                l1 = l1->next;
                l2 = l2->next;
            }
            else{
                l3->val += l1->val;
                if(l3->val >= 10){
                    l3->val %= 10;
                    l3->next = new ListNode(1);
                }
                l1 = l1->next;
            }
        }
        while (l2 != nullptr)
        {
            if(l3 == nullptr){
                l3 = l = new ListNode(0);
            }
            else{
                if(l3->next == nullptr){
                    l3->next = new ListNode(0);
                }
                l3 = l3->next;
            }
            l3->val += l2->val;
            if(l3->val >= 10){
                l3->val %= 10;
                l3->next = new ListNode(1);
            }
            l2 = l2->next;
        }
        return l;
    }

    ListNode* get(ListNode *l, int pos){
        while(--pos){
            l = l->next;
        }
        return l;
    }
    
    void question2_2_2(ListNode *l1, int m, int n){
        ListNode *l = l1;
        for(int i=1; (l!=nullptr)&&(i<=(m+n)/2); l=l->next, i++){
            if(i >= m){
                int tmp = l->val;
                l->val = get(l, n-(i-m)-i+1)->val;
                get(l, n-(i-m)-i+1)->val = tmp;
            }
        }
    }
    ListNode* question2_2_2_method2(ListNode *l1, int m, int n){
        ListNode dummy(-1);
        dummy.next = l1;
        ListNode *head = &dummy;
        for(int i=0; i<m-1; i++){
            head = head->next;
        }
        ListNode *end = head->next;
        ListNode *cur = end->next;
        ListNode *tmp;
        for(int i=m+1; i<=n; i++){
            tmp = cur->next;
            cur->next = head->next;
            head->next = cur;
            cur = tmp;
        }
        end->next = tmp;
        return dummy.next;
    }
};

test_leetCodeShuati::test_leetCodeShuati(/* args */)
{
    ilog("test leetCodeShuati in");
    //vector<int> v1={1,2,2,3,1,2,4,4,5,5};
    vector<int> v1={1,2,2,2,2,2,3,4,4,5,5,5};
    int len=0;
    //len = removeDuplicates(v1);
    //len = question2_1_1(v1);
    //len = question2_1_1_2(v1);
    //unique(v1.begin(),v1.end());
    //len=v1.size();
    //len = question2_1_1_3(v1);
    //len = question_2_1_2(v1);
    // len = removeDuplicates(v1);
    // cout << "len=" << len << endl;
    // print(v1);

    // vector v2={4,5,6,7,0,1,2};
    // int index = question2_1_3(v2, 2);
    // cout << "index is " << index << endl;

    //vector<int> v3={100, 4, 200, 1, 3, 2};
    //len = question2_1_6(v3);
    //cout << "len is " << len << endl;

    // vector<int> v4={2, 6, 11, 15, 7, 9};
    // std::tuple<int,int> t;
    // t = question2_1_7(v4, 9);
    // cout << "index1 = "<< std::get<0>(t) << "index2 = " << std::get<1>(t) << endl;
    
    // vector<int> v5={0,1,0,2,1,0,1,3,2,1,2,1};
    // //len = question2_1_15(v5);
    // len = question2_1_15_method2(v5);
    // cout << "len is " << len << endl;

    // int fn = question2_1_18(5);
    // cout << "fn = "<< fn << endl;
    // vector<vector<int>> vv={{1,2,3},{0,5,6},{7,8,9},{10,11,12}};
    // question2_1_20(vv);
    // print(vv);

    ListNode* l1;
    ListNode* l2;
    l1 = new ListNode(1);
    l1->next = new ListNode(2);
    l1->next->next = new ListNode(3);
    l1->next->next->next = new ListNode(4);
    l1->next->next->next->next = new ListNode(5);
    l2 = new ListNode(1);
    l2->next = new ListNode(2);
    l2->next->next = new ListNode(3);
    l2->next->next->next = new ListNode(4);
    // ListNode *l3 = question2_2_1(l1, l2);
    // print(l3);
    //question2_2_2(l1, 1,4);
    ListNode* l3 = question2_2_2_method2(l1, 3,4);
    print(l3);
}

test_leetCodeShuati::~test_leetCodeShuati()
{

}
