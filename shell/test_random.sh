#!/bin/bash

function random(){
    min=$1;
    max=$2-$1;
    num=$(date +%N);
    num=`echo $num | sed -r 's/^0+//'`
    ((retnum=num%max+min));
    #进行求余数运算即可
    echo $retnum;
}
function test_random(){
    for i in {1..10};
    do 
        out=$(random 2 10000);
        echo $i,"2-10000",$out;
        echo "RANDOM: " $RANDOM
    done;
}
test_random