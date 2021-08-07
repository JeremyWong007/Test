#!/bin/bash

echo "Hello shell test!"

test_map(){
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

test_yunsuanfu(){
    echo "test yunsuanfu start:"
    value=`expr 2 + 3 `
    value=`expr 2 - 3 `
    value=`expr 2 \* 3 `
    value=`expr 9 / 3 `
    value=`expr 2 % 3 `
    echo $value
}

test_array(){
    echo "test array start:"
    fruit=("apple" "orange" "banana")
    for element in ${fruit[@]}
    do
        echo $element
    done
    echo "array length is ${#fruit[@]}"
}

test_readonly(){
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



arr[1]="111"
arr[3]="333"
echo ${arr[3]}

accountArray=(
T1hNQ2VW9rowZkdhyWem74MfUeEADN4h
T122SMYKYGrxjNPqbG9wenr4XhPjbVxtH
)
echo ${accountArray[0]}

function setcmd(){
    CMD="command"
}
setcmd
echo $CMD
testParam $@
testForDo
testSeq
testRandom
test_readonly
test_array
test_yunsuanfu
test_map