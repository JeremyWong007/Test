#!/bin/bash

function test_disk(){
    sudo fdisk -l
}

function test_awk(){
    ps -e | grep taf | awk '{print $1}' |xargs kill -9  #获取taf匹配的进程id，并强制杀死
}

function test_sed(){
    echo "test sed start"
}
function test_string(){
    echo "test string start"
    str="24332 pts/11   00:00:00 tafcored"
    str1=${str:0:5}  #从左边开始截取
    str2=${str:0-8:8}  #从右边开始截取
    echo $str
    echo $str1
    echo $str2
    url="http://c.biancheng.net/index.html"
    echo ${url#*/}  #截取右边 第一个/
    echo ${url##*/} #截取右边 最后第一个/
    path="/data/info/git/test/shell"
    echo ${path%shell} #删除shell
    text=" 123 456 "
    text=${text/ /-}  #只替换一个
    text=${text// /-}  #全部替换
}

function test_net(){
    echo "test net start"
    netstat -al | grep LISTEN
}

function test_if_else(){
    echo "test if_else start"
    version="default"
    if [ $version == "default" ];
    then
        echo "default"
    else
        echo "Not default"
    fi
    echo "End"
}

function test_map(){
    echo "test map start:"
    declare -A mymap
    mymap["apple"]="red"
    mymap["banana"]="yellow"
    mymap["orange"]="green"
    echo ${mymap["apple"]}
    echo "输出所有value:${mymap[@]}"
    echo "输出所有key:${!mymap[@]}"
    echo "map长度:${#mymap[@]}"
}

function test_yunsuanfu(){
    echo "test yunsuanfu start:"
    value=`expr 2 + 3 `
    value=`expr 2 - 3 `
    value=`expr 2 \* 3 `
    value=`expr 9 / 3 `
    value=`expr 2 % 3 `
    echo $value
}

function test_array(){
    echo "test array start:"
    fruit=("apple" "orange" "banana")
    for element in ${fruit[@]}
    do
        echo $element
    done
    echo "array length is ${#fruit[@]}"
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
    for((i=0;i<10;i++))
    do
        echo $i
    done
    
    for i in apple orange banana
    do
        echo $i
    done

    #for i in /etc/*
    #do
    #    echo $i
    #done

    for i in $(ls)
    do
        echo $i
    done

    for i in $(seq -w 10)
    do
        echo $i
    done
}

#入参相关
function testParam(){
    echo "test param start"
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

test_if_else
testParam $@
testForDo
testSeq
testRandom
test_readonly
test_array
test_map
test_yunsuanfu
test_string