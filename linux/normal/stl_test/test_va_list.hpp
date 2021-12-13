#include "../common.h"

using namespace std;

/*
可变参数：
1 宏传递可变参数，例如 #define dlog(__fmt__, ...)   mainCategory.debug(__format(__fmt__),__FILE__, __LINE__,##__VA_ARGS__)
2 变参传给printf，改用vprintf，说明传递可变参数的方法为：使用va_list参数
3 可变模板参数，实现变参传递
    // template<typename Func, typename... Args>
    // static void test_runTime(Func f, Args... a){
    //     f(a...);
    // }
*/
class test_va_list
{
private:
    /* data */
public:
    test_va_list(/* args */);
    ~test_va_list();
    void log(const char* fmt, ...){
        //char str[256] = {0};
        va_list args;
        va_start(args, fmt);
        //浪费空间和时间的错误方法：
        //vsnprintf(str, 256, fmt, args);
        //printf("%s", str);
        vprintf(fmt, args);
        va_end(args);
    }
    void fun(int a,...){
        va_list ap; 
        va_start(ap, a); 
        int i;
        for(i=0; i<a; i++){
            printf("%d\t",va_arg(ap,int));
        }   
        putchar('\n');
        va_end(ap);
    }
};

test_va_list::test_va_list(/* args */)
{
    ilog("test va_list in");
    int i = 3;
    const char* str = "Haha";
    log("Hello %drd world, %s.\n", i, str);

    fun(4,1,2,3,4);
    printf("--------------------------------\n");
    fun(4,1,2,"ab","cd");
}

test_va_list::~test_va_list()
{
}
