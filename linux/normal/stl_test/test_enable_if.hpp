#pragma once
#include "../common.h"

class Apple{
    public:
    const static bool value = true;
};
class Orangle{
    public:
    const static bool value = true;
};
template<typename T, typename T1=void>
class check;
template<typename T>
class check<T, typename std::enable_if<T::value>::type>{
    private:
    bool value = T::value;
};
template<typename T>
typename std::enable_if<std::is_integral<T>::value, bool>::type
is_odd(T t){
    return bool(t % 2);
}
//template <typename T, typename = typename std::enable_if<std::is_integral<T>::value>::type>
template <typename T, typename = typename std::enable_if<std::is_integral<T>::value>::type>
bool is_even(T t) {
  return !is_odd(t); 
}

class test_enable_if
{
private:
    /* data */
public:
    test_enable_if(/* args */);
    ~test_enable_if();
};

test_enable_if::test_enable_if(/* args */)
{    
    ilog("test enable_if in");
    check<Apple> a;
    is_odd(12);
    is_even<>(12);
}

test_enable_if::~test_enable_if()
{
}
