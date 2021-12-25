/* heap
应用：数据流中的中位数 https://www.cnblogs.com/MrLiuZF/p/13498631.html
　　如何得到一个数据流中的中位数？如果从数据流中读出奇数个数值，那么中位数就是所有数值排序之后位于中间的数值。如果从数据流中读出偶数个数值，那么中位数就是所有数值排序之后中间两个数的平均值。我们使用Insert()方法读取数据流，使用GetMedian()方法获取当前读取数据的中位数。
解决：
　　采用大顶堆和小顶堆实现。把数据分为两部分，左边部分整体上要小于右边部分。
　　左边部分为大顶堆，右边部分为小顶堆，往两边堆中不断插入数据。
　　当数据总数为偶数时，插入到min堆，总数为奇数时，插入到max堆。插入过程中要保证左边部分总体小于右边部分，要不断调整。最后，总数为偶数时候，中位数为max堆顶元素和min堆顶元素之和的平均，为奇数，则为min堆的堆顶元素。
*/

#include "../common.h"
#include <algorithm>

using namespace std;

class test_heap
{
private:
    /* data */
public:
    test_heap(/* args */);
    ~test_heap();
    void print_heap(std::vector<int> v){
        cout << "print heap:";
        for(auto i : v){
            cout << " " << i;
        }
        cout << endl;
    }
};

test_heap::test_heap(/* args */)
{
    ilog("test heap in");
    std::vector<int> v={1, 2, 3, 4, 5, 6, 7, 8};
    make_heap(v.begin(), v.end(), less<int>());
    print_heap(v);
    make_heap(v.begin(), v.end());
    print_heap(v);
    // make_heap(v.begin(), v.end(), greater<int>());
    // print_heap(v);
    cout << "push back" << endl;
    v.push_back(15);
    push_heap(v.begin(), v.end());
    print_heap(v);
    cout << "pop heap" << endl;
    pop_heap(v.begin(), v.end());
    print_heap(v);
    v.pop_back();
    print_heap(v);
    cout << "sort heap" << endl;
    sort_heap(v.begin(), v.end());
    print_heap(v);

    cout << "min heap" << endl;
    make_heap(v.begin(), v.end(), greater<int>());
    print_heap(v);
    cout << "push back" << endl;
    v.push_back(15);
    push_heap(v.begin(), v.end(), greater<int>());
    print_heap(v);
    cout << "pop heap" << endl;
    pop_heap(v.begin(), v.end(), greater<int>());
    print_heap(v);
    v.pop_back();
    print_heap(v);
    cout << "sort heap" << endl;
    //sort_heap(v.begin(), v.end());
    //print_heap(v);
    sort_heap(v.begin(), v.end(), greater<int>());
    print_heap(v);
}

test_heap::~test_heap()
{
}
