#!/bin/bash
set -u

#拷贝所有文件
pkill nodeos
pkill tafwalletd 
sleep 0.1
version=$1
cd /data/info/file
#scp -r yanfa-03@192.168.0.232:/data/info/download/release_${version} ./
scp -i /data/info/tafchain.pem -r root@121.41.193.65:/data/info/download/release_${version} ./

#安装bin文件
rm -rf  ~/eosio
mkdir -p ~/eosio/2.0/
cp -rf release_${version}/bin ~/eosio/2.0/
export PATH=$PATH:~/eosio/2.0/bin
