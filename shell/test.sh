#!/bin/bash

function test_disk(){
    sudo fdisk -l
}

function test_awk(){
    ps -e | grep taf | awk '{print $1}' |xargs kill -9  #获取taf匹配的进程id，并强制杀死
}

function test_sed(){
    
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

function test_map_arr(){
    echo "test map start"
    declare -A map
    mymap["apple"]="pen"
    echo ${mymap["apple"]}

    arr[1]="111"
    arr[3]="333"
    echo ${arr[3]}

    accountArray=(
    T1hNQ2VW9rowZkdhyWem74MfUeEADN4h
    T122SMYKYGrxjNPqbG9wenr4XhPjbVxtH
    )
    echo ${accountArray[0]}
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

echo "============ Shell Test =========="
test_map_arr
test_if_else
test_string