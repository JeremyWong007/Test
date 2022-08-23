#！/bin/bash

function getContractPath(){
    path=$1
    if [ "${path:0:1}" == "/" ]; then
    {
        #echo "Absolute address"
        CONTRACT_PATH=$path
    }
    elif [ "${path:0:2}" == "./" ]; then
    {
        #echo "Relative address"
        CONTRACT_PATH=$(pwd)${path#.}
    }
    elif [ "$path" == "" ]; then
    {
        #echo "Default address"
        CONTRACT_PATH="/data/info/git/contracts/build/contracts/"
    }
    else
    {
        #echo "Short address"
        CONTRACT_PATH="/data/info/file/release_${path}/contracts/"
    }
    fi
    echo "CONTRACT_PATH is $CONTRACT_PATH"
}

function pkillAndWait(){
    threadName=$1
    pkill $threadName
    sleep 0.5
    for((i=0;i<300;i++))
    do
        result=`ps -e | grep $threadName | awk '{print \$4}'`
        if [ "$result" != "$threadName" ]; then
            echo "kill ok $threadName"
            return 0
        fi
        echo "kill again $i"
        pkill $threadName
        sleep 1
    done
    echo "Fail to kill $threadName"
    exit
    return -1
}

function getApplicationName(){
    if [ "$#" == "0" ]; then
    {
        APPLICATION_NAME="mcp"
        APPLICATION_PATH_NAME="/root/ccn/git/mcp/build/mcp"
        APPLICATION_PATH="/root/ccn/git/mcp/build/"
        
        echo "APPLICATION_PATH_NAME="$APPLICATION_PATH_NAME
        echo "APPLICATION_NAME="$APPLICATION_NAME
        return
    }
    fi

    APPLICATION_NAME="$1"

    if [ "$1" == "mcp" ]; then
    {
        APPLICATION_PATH_NAME="/root/ccn/git/mcp/build/mcp"
    }
    elif [ "$1" == "test1" ]; then
    {
        APPLICATION_PATH_NAME="/root/ccn/file/test1"
    }
    else
    {
        APPLICATION_PATH_NAME="$1"
        APPLICATION_NAME=${APPLICATION_PATH_NAME##*/}
    }
    fi
    echo "APPLICATION_PATH_NAME="$APPLICATION_PATH_NAME
    echo "APPLICATION_NAME="$APPLICATION_NAME
}

