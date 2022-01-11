#!/bin/bash

str="/data/info/file/release_8.1/hello.txt"

#内置操作符 https://www.cnblogs.com/chengmo/archive/2010/10/02/1841355.html
#长度
echo "length = ${#str}"

#按位置截取
echo ${str:6:4}
echo ${str:0-9:5}  #从右边开始数9位，取5位字符

#前后截断
echo ${str##*/}
echo ${str%/*}

#替换
echo ${str/hello/nice}
echo ${str/#\/data/\/etc}

#调用外部命令
echo "2014年7月21日" | tr -cd "[0-9]" #从字符串中提取数字