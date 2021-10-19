#!/bin/bash

#知识点：
#echo "yongqi001" | sudo -S touch cc  #带密码执行sudo

#疑问：
#export CURRENT_USER=${CURRENT_USER:-$(whoami)}

function test_disk(){
    sudo fdisk -l
}

function test_awk(){
    ps -e | grep taf | awk '{print $1}' |xargs kill -9  #获取taf匹配的进程id，并强制杀死
}

function test_sed(){
    echo "test sed start"
    sed  's/123/hello/'   r.txt   #将文件中的123替换为hello，默认只替换每行第一个123
    sed  -i 's/123/hello/'   w.txt   #将文件中的123替换为hello，默认只替换每行第一个123
}
function test_string(){
    echo "#############################测试字符处理#############################"
    str="24332 pts/11   00:00:00 tafcored"
    str1=${str:0:5}  #从左边开始截取
    str2=${str:0-8:8}  #从右边开始截取
    echo $str
    echo $str1
    echo $str2
    url="http://c.biancheng.net/index.html"
    echo ${url#*/}  #截去头部（左边） 取第一个/的右边
    echo ${url##*/} #截去头部（左边） 取最后第一个/的右边
    path="/data/info/git/test/shell"
    echo ${path%shell} #截去尾部（右边） 去掉shell
    text=" 123 456 "
    text=${text/ /-}  #只替换一个
    text=${text// /-}  #全部替换
    echo "2014年7月21日" | tr -cd "[0-9]" #从字符串中提取数字
}

function test_net(){
    echo "test net start"
    netstat -al | grep LISTEN
    #nc -l 8888  #监听8888端口
    #telnet 127.0.0.1 8888  #测试8888端口通讯
    #netstat -ntpl  #查看监听的TCP端口状态
}

function test_linux_cmd(){
    echo "test linux command start"
    #ps -aux | grep taf #查看tafcored详细启动命令
    test_net
}

function test_yunsuanfu(){
    echo "#############################测试运算符#############################"
    #算术运算符
    a=10
    b=20
    val=`expr $a + $b`
    echo "a + b : $val"
    val=`expr $a - $b`
    echo "a - b : $val"
    val=`expr $a \* $b`
    echo "a * b : $val"
    val=`expr $b / $a`
    echo "b / a : $val"
    val=`expr $b % $a`
    echo "b % a : $val"
    if [ $a == $b ]; then
        echo "a 等于 b"
    fi
    if [ $a != $b ]; then
        echo "a 不等于 b"
    fi

    #关系运算符 关系运算符只支持数字，不支持字符串，除非字符串的值是数字。
    if [ $a -eq $b ]
    then
        echo "$a -eq $b : a 等于 b"
    else
        echo "$a -eq $b: a 不等于 b"
    fi
    if [ $a -ne $b ]
    then
        echo "$a -ne $b: a 不等于 b"
    else
        echo "$a -ne $b : a 等于 b"
    fi
    if [ $a -gt $b ]
    then
        echo "$a -gt $b: a 大于 b"
    else
        echo "$a -gt $b: a 不大于 b"
    fi
    if [ $a -lt $b ]
    then
        echo "$a -lt $b: a 小于 b"
    else
        echo "$a -lt $b: a 不小于 b"
    fi
    if [ $a -ge $b ]
    then
        echo "$a -ge $b: a 大于或等于 b"
    else
        echo "$a -ge $b: a 小于 b"
    fi
    if [ $a -le $b ]
    then
        echo "$a -le $b: a 小于或等于 b"
    else
        echo "$a -le $b: a 大于 b"
    fi

#布尔运算符
:<<YUNSUNFU
运算符	说明	举例
!	非运算，表达式为 true 则返回 false，否则返回 true。	[ ! false ] 返回 true。
-o	或运算，有一个表达式为 true 则返回 true。	[ $a -lt 20 -o $b -gt 100 ] 返回 true。
-a	与运算，两个表达式都为 true 才返回 true。	[ $a -lt 20 -a $b -gt 100 ] 返回 false。
YUNSUNFU

    #逻辑运算符
    if [[ $a -lt 100 && $b -gt 100 ]]
    then
        echo "返回 true"
    else
        echo "返回 false"
    fi

    if [[ $a -lt 100 || $b -gt 100 ]]
    then
        echo "返回 true"
    else
        echo "返回 false"
    fi

#字符串运算符
:<<YUNSUNFU
下表列出了常用的字符串运算符，假定变量 a 为 "abc"，变量 b 为 "efg"：

运算符	说明	举例
=	检测两个字符串是否相等，相等返回 true。	[ $a = $b ] 返回 false。
!=	检测两个字符串是否不相等，不相等返回 true。	[ $a != $b ] 返回 true。
-z	检测字符串长度是否为0，为0返回 true。	[ -z $a ] 返回 false。
-n	检测字符串长度是否不为 0，不为 0 返回 true。	[ -n "$a" ] 返回 true。
$	检测字符串是否为空，不为空返回 true。	[ $a ] 返回 true。
YUNSUNFU
}

function test_map(){
    echo "#############################测试MAP#############################"
    declare -A mymap
    mymap["banana"]="yellow"
    mymap["apple"]="red"
    mymap["orange"]="green"
    echo ${mymap["apple"]}
    echo "输出所有value:${mymap[@]}"
    echo "输出所有key:${!mymap[@]}"
    echo "map长度:${#mymap[@]}"
}

function test_array(){
    echo "#############################测试数组#############################"
    fruit=("banana" "apple" "orange")
    for element in ${fruit[@]}; do
        echo $element
    done
    echo "array length is ${#fruit[@]}"
    echo "fruit[0]=${fruit[0]}"
    i="1"
    echo "fruit[1]=${fruit[i]}"
}

function test_readonly(){
    echo "test readonly start:"
    myname="king"
    readonly myname
    #myname="baby"
}

function testRandom(){
    echo "test random start:"
    for i in {0..9};do echo $RANDOM;done
}

function testSeq(){
    echo "test seq start:"
    seq -w 22 2 27 #在列前添加0 使得宽度相同【自动补位】
    seq -s '#' 5 #使用指定字符串分隔数字(默认使用：\n)
    seq -f "%03g" 98 101 #使用printf 样式的浮点格式
}

#for功能
function testForDo(){
    echo "test for start"
    for((i=0;i<10;i++)); do
        echo $i
    done
    
    for i in apple orange banana; do
        if [ "$i" == "orange" ]; then
            echo "hello orange"
            continue
        fi
        echo $i
    done

    #for i in /etc/*; do
    #    echo $i
    #done

    for i in $(ls); do
        echo $i
    done

    for i in $(seq -w 10); do
        echo $i
    done
}

#入参相关
function testParam(){
    echo "#############################测试参数传递#############################"
    echo "执行的文件名：$0"
    echo "第一个参数为：$1"
    echo "第二个参数为：$2"
    echo "第三个参数为：$3"
    echo "参数个数为：$#"
    echo "所有参数显示：$*"
    echo "所有参数显示："$@""
    echo "当前进程id：$$"
    echo "当前选项：$-"
    echo "最后命令的退出状态：$?"
}

echo "============ Shell Test =========="

testParam $@
testForDo
testSeq
testRandom
test_readonly
test_array
test_map
test_yunsuanfu
test_string
test_sed
test_linux_cmd