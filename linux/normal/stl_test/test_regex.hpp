#include "../common.h"
#include <regex>
#include <iostream>

using namespace std;
class test_regex
{
private:
    /* data */
public:
    test_regex(/* args */);
    ~test_regex();

    /*
    调用方法： ./test1 < test.html 
    */
    void search_html(){
        std::string tmp,html;
        while (getline(std::cin, tmp))
        {
            tmp += '\n';
            html += tmp;
        }
        //std::string pattern("http(s)?://([\\w-]+\\.)+[\\w-]+(/[\\w- ./?%&=]*)?");
        std::string pattern("id=.*");
        //pattern = "[[:alpha:]]*" + pattern + "[[:alpha:]]*";
        std::regex r(pattern);
        for (std::sregex_iterator it(html.begin(), html.end(), r), end;     //end是尾后迭代器，regex_iterator是regex_iterator的string类型的版本
            it != end;
            ++it)
        {
            std::cout << it->str() << std::endl;
        }
    }
};

test_regex::test_regex(/* args */)
{
    ilog("test regex in");
    search_html();
}

test_regex::~test_regex()
{
}
