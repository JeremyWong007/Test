#!/bin/bash

echo "Hello shell test!"

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

function setcmd(){
    CMD="command"
}
setcmd
echo $CMD