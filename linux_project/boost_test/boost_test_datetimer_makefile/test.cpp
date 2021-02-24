//注：未成功编译
// Copyright (c) 2015
// Author: Chrono Law
#include <cassert>
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <numeric>
using namespace std;

//#define DATE_TIME_NO_DEFAULT_CONSTRUCTOR
#include <boost/date_time/gregorian/gregorian.hpp>
using namespace boost::gregorian;

//////////////////////////////////////////

//////////////////////////////////////////
void case1()
{
    date d1;
    date d2(2010,1,1);
    date d3(2000, Jan , 1);
    date d4(d2);

    assert(d1 == date(not_a_date_time));
    assert(d2 == d4);
    assert(d3 <  d4);
}

//////////////////////////////////////////

void case2()
{
    date d1 = from_string("1999-12-31");
    date d2 ( from_string("2015/1/1") );
    date d3 = from_undelimited_string("20011118") ;

    cout << d1 << d2 << d3 << endl;

    cout << day_clock::local_day()    << endl;
    cout << day_clock::universal_day() << endl;

}

int main()
{
    cout<<"Hello boost!"<<endl;
    case1();
    case2();
}


