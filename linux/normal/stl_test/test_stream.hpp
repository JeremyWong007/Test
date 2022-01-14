/*stream
使用场景：
1 格式转换
2 string s; getline(cin,s); stringstream ss(s); for(string s1;ss>>s1;cout<<s1<<endl); 

注意：
1 如果你打算在多次转换中使用同一个stringstream对象，记住在每次转换前要使用clear()方法；
2 那么把stringstream类内部的缓冲区正确的清空方式是什么呢? stringstream ss; 答案是: ss.str(“”) 
3 所以, 保险起见, 每次缓冲区格式化后, 都通过clear(), str(“”) 两个函数都调用, 把stingstream类复位.

fstream
std::ios_base::openmode
in	    input File	读的方式打开文件
out	    output	    写的方式打开文件
binary	binary	    二进制方式打开
ate	    at end	    打开的时候定位到文件末尾
app	    append	    所有操作都定位到文件末尾
trunc	truncate	丢弃打开前文件存在的内容

seekp：设置输出文件流的文件流指针位置
seekg：设置输入文件流的文件流指针位置
ostream& seekp( streampos pos );
ostream& seekp( streamoff off, ios::seek_dir dir );
istream& seekg( streampos pos );
istream& seekg( streamoff off, ios::seek_dir dir );
ios_base::beg	beginning of the stream
ios_base::cur	current position in the stream
ios_base::end	end of the stream

//（二）、保护模式
//#define _SH_DENYRW      0x10     deny read/write mode 拒绝对文件进行读写 
//#define _SH_DENYWR      0x20     deny write mode 拒绝写入文件 
//#define _SH_DENYRD      0x30     deny read mode 拒绝文件的读取权限 
//#define _SH_DENYNO      0x40     deny none mode 读取和写入许可 
//#define _SH_SECURE      0x80     secure mode 共享读取，独占写入 
//注意：假设A进程以_SH_DENYRW 打开，那么是B进程不能再对文件进行读写。

locale loc = locale::global(locale("")); 		       //要打开的文件路径含中文，设置全局locale为本地环境 
locale::global(loc);					      //恢复全局locale
*/

#include "../common.h"
#include <sstream>
#include <iostream>
#include <fstream>

#include <string>
#include <stdio.h>

using namespace std;

class test_stream
{
private:
    /* data */
public:
    test_stream(/* args */);
    ~test_stream();
    
    void test_fstream(){
        ilog("test fstream in");
        #if 0
        ifstream file;
        file.open("../input.txt", std::ios_base::in);
        if(file){
            stringstream ss;
            string str,str2;
            while(getline(file, str)){
                //cout<<str<<endl;
                stringstream ss(str);
                while (getline(ss, str2, ' '))
                {
                    cout<<str2<<endl;
                }
                // while(ss>>str2){
                //     cout<<str2<<endl;
                // }
            }
            file.close();
        }
        #endif
        #if 1
        ofstream file2;
        file2.open("../input.txt");  //注意，ofstream默认打开时，<<操作会删除旧的文件。而fstream方式打开，则不会。
        if(file2){
            // file2.seekp(10, ios_base::beg);
            // file2 << "Hello 1.14"<<std::endl;
            // file2 << "Hello 1.15"<<std::endl;
            //file2.put()
            file2.close();
        }
        #endif

        #if 0
        fstream file3("../input.txt", std::ios_base::in | std::ios_base::out | std::ios_base::binary);
        if(file3){
            if(file3.eof()){
                std::cout<<"已到达文件尾!"<<endl;
            }
            cout<<"tellg:"<<file3.tellg()<<endl;
            cout<<"tellp:"<<file3.tellp()<<endl;
            file3.seekp(0, ios_base::end);
            if(file3.eof()){
                std::cout<<"已到达文件尾!"<<endl;
            }
            cout<<"tellg:"<<file3.tellg()<<endl;
            cout<<"tellp:"<<file3.tellp()<<endl;
            file3 << "Hello wrold!";
            if(file3.eof()){
                std::cout<<"已到达文件尾!"<<endl;
            }
            file3.seekp(50);
            file3 << "Hello wrold!";
            std::string str;
            file3.seekp(2, ios_base::beg);
            cout<<"tellg:"<<file3.tellg()<<endl;
            cout<<"tellp:"<<file3.tellp()<<endl;
            file3 >> str;
            cout<<"str2:"<<str<<endl;
            file3.seekp(-3, ios_base::end);
            file3 >> str;
            cout<<"str:"<<str<<endl;
            file3.close();
        }
        #endif
    }
};

test_stream::test_stream(/* args */)
{
    ilog("test stream in");
    string str="114 Hello", str3;
    int i=0;
    stringstream sst;
    sst << "115";
    //sst >> str3;
    cout << "i=" << str3 <<endl;
    //sst.clear();
    //sst.str("");
    sst << "haha";
    //sst << "heihei";
    sst >> str3;
    cout << str3<<endl;
    cout << str3<<endl;
    cout<<sst.str()<<endl;

    stringstream sstream;
    // 将多个字符串放入 sstream 中
    sstream << "first" << " " << "string,";
    sstream << " second string";
    cout << "strResult is: " << sstream.str() << endl;
 
    // 清空 sstream
    //sstream.str("");
    sstream << "third string";
    cout << "After clear, strResult is: " << sstream.str() << endl;

    int a=119;
    float f=11.22;
    //string str4;
    //tools::to_string(str4, a);
    //cout<<"str4:"<<str4<<endl;
    //tools::to_string(str4, f);
    //cout<<"str4:"<<str4<<endl;
    cout<<tools::convert<string>(a)<<endl;
    cout<<tools::convert<string>(f)<<endl;

    // string str5;
    // getline(cin, str5, ',');
    // cout<<"str5: "<<str5<<endl;
    // stringstream ss(str5);
    // for(string str; ss>>str; cout<<str<<endl);

    test_fstream();
}

test_stream::~test_stream()
{
}
