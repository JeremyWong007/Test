#!/bin/bash

# 部署多节点使用说明：
#1 服务器1启动：./simple_deploy.sh
#2 服务器2，首先启动firt节点，与其它服务器连接： ./simple_deploy_server2.sh first
#3 服务器2，启动多个节点，例如启动序号0-50节点：  ./simple_deploy_server2.sh 0 50
#2 服务器3，首先启动firt节点，与其它服务器连接： ./simple_deploy_server2.sh first
#3 服务器3，启动多个节点，例如启动序号50-100节点：  ./simple_deploy_server2.sh 50 100
#4 服务器4，与服务器2、3启动方法一致
#注意：服务器2、3、4等，都使用simple_deploy_server2.sh脚本，通过不同的序号配置不同的帐户。每个服务器可配置不同数量的节点，但需要注意序号不可重叠

#set -x

source globalInfo.sh

WORK_NODES=50 #实际总节点数量为（WORK_NODES+创世节点）
MAKER_NUM=40 #生产者数量，要求（<=WORK_NODES）

GENESIS_ACCOUNT="T1HHsxQ3igveVAfbXipkWH89J6VFS5QGF6T"
GENESIS_ACCOUNT_PROVIDER="EOS6Kc7LVUHVxauut2rj8Rwk21mXAYpvLoNsJf3C1vFLFjhGeeHHM=KEY:5JLrjLzKiWvecrUkBBPEBm4Wt8F7ECygLNnLhhLW64fCGP5RUvH"

getContractPath $@

if [ "${#private_keys[@]}" -ne "${#public_keys[@]}" ]; then
    echo "public key and private key count not equal"
    exit 0
fi

if [ "$WORK_NODES" -gt "${#private_keys[@]}" ]; then
    echo "work node is too big"
    exit 0
fi

ProducerNameArray=()

killall nodeos
rm -rf /tmp/rctest/*

# unlock wallet
./unlock.sh

# import private keys
for((i=0;i<$WORK_NODES;i++));
do
    PRIV_KEY=${private_keys[i]}
    cleos wallet importkey --private-key $PRIV_KEY
done

# start genesis node
HTTP_LISTEN_PORT=8888
P2P_LISTEN_PORT=9510
P2P_LISTEN_PORT_TO=`expr 9510 + 1`
DATADIR="/tmp/rctest/genesis"
PROVIDER=$GENESIS_ACCOUNT_PROVIDER
NAME=$GENESIS_ACCOUNT

mkdir -p "$DATADIR"

CMD="nodeos \
--plugin eosio::producer_plugin \
--plugin eosio::producer_api_plugin \
--plugin eosio::chain_plugin \
--plugin eosio::chain_api_plugin \
--plugin eosio::http_plugin \
--plugin eosio::history_api_plugin \
--plugin eosio::history_plugin \
--data-dir $DATADIR"/data" \
--blocks-dir $DATADIR"/blocks" \
--config-dir $DATADIR"/config" \
--access-control-allow-origin=* \
--contracts-console \
--http-validate-host=false \
--verbose-http-errors \
--enable-stale-production \
--abi-serializer-max-time-ms 1000000 \
--http-max-response-time-ms 500 \
--max-transaction-time 1000 \
--keosd-provider-timeout 5000 \
--p2p-max-nodes-per-host 200 \
--chain-state-db-size-mb=102400 \
--genesis-json "../genesis.json" \
--logconf=../logging.json \
--http-server-address 0.0.0.0:$HTTP_LISTEN_PORT \
--p2p-listen-endpoint 0.0.0.0:$P2P_LISTEN_PORT \
--p2p-peer-address localhost:$P2P_LISTEN_PORT_TO \
--producer-name $NAME \
--signature-provider $PROVIDER \
>> $DATADIR"/nodeos.log" 2>&1 & \
echo $! > $DATADIR"/eosd.pid" "

echo $CMD
eval $CMD

sleep 1

# create all account and get name
echo "create all account and get name:"
for((i=0;i<$WORK_NODES;i++));
do
    PUB_KEY=${public_keys[i]}
    RSP=`cleos new account $PUB_KEY`
    RESULT=`echo $RSP | awk -F 'account address: ' '{print $2}' `
    # if is empty, exit
    ProducerNameArray[i]=$RESULT
    echo $i $RESULT
done

# start work nodes
for((i=0;i<$WORK_NODES;i++));
do
    HTTP_LISTEN_PORT=`expr 8888 + $i + 1`
    P2P_LISTEN_PORT=`expr 9510 + $i + 1`
    P2P_LISTEN_PORT_TO=`expr $P2P_LISTEN_PORT - 1`
    DATADIR="/tmp/rctest/$i"
    PROVIDER="EOS5EfU2fDgHZTNwPhuoHJgKcrNJ3PbyaYMHMrgMnBpVffWjgeJjX=KEY:5HxK6mfoNr1pbnbYs1AmsKjavJQaoxiNVUdeJD6ZPFZkQvGcZVM"
    NAME=${ProducerNameArray[i]}

    mkdir -p "$DATADIR"

    CMD="nodeos \
    --plugin eosio::producer_plugin \
    --plugin eosio::producer_api_plugin \
    --plugin eosio::chain_plugin \
    --plugin eosio::chain_api_plugin \
    --plugin eosio::http_plugin \
    --plugin eosio::history_api_plugin \
    --plugin eosio::history_plugin \
    --data-dir $DATADIR"/data" \
    --blocks-dir $DATADIR"/blocks" \
    --config-dir $DATADIR"/config" \
    --access-control-allow-origin=* \
    --contracts-console \
    --http-validate-host=false \
    --verbose-http-errors \
    --enable-stale-production \
    --abi-serializer-max-time-ms 1000000 \
    --http-max-response-time-ms 500 \
    --max-transaction-time 1000 \
    --keosd-provider-timeout 5000 \
    --p2p-max-nodes-per-host 200 \
    --chain-state-db-size-mb=102400 \
    --genesis-json "../genesis.json" \
    --logconf=../logging.json \
    --http-server-address 0.0.0.0:$HTTP_LISTEN_PORT \
    --p2p-listen-endpoint 0.0.0.0:$P2P_LISTEN_PORT \
    --p2p-peer-address localhost:$P2P_LISTEN_PORT_TO \
    --producer-name $NAME \
    --signature-provider $PROVIDER \
    >> $DATADIR"/nodeos.log" 2>&1 & \
    echo $! > $DATADIR"/eosd.pid" "

    echo $CMD
    eval $CMD
done

sleep 1

# set contract
./setConfigNormal.sh $CONTRACT_PATH

#基金会帐户 account address: T17Y2vaQtyQmGVm3MZrvS3hGFj5zVXvo48S
cleos wallet importkey --private-key 5KENnPegq7hiPBZYRuuD8x4QonnqErFWz4gMiSGCNEcRvvb4KJE
cleos new account EOS8VS2tKPTznw8BntttKxGzCR6rupgQYeh8LmKj7dXNAsMZYj8NJ
cleos transfer T1HHsxQ3igveVAfbXipkWH89J6VFS5QGF6T T17Y2vaQtyQmGVm3MZrvS3hGFj5zVXvo48S "240000000.0000 EOS"

#团队帐户 account address: T1BvMyqRo9BnHKi1DamjF1MwWcGT3EGfrCA
cleos wallet importkey --private-key 5JGdHMeVJc2SpvnY8UPLu4TyxUE3AXQFoxM2pC44hVzvyHKiBYZ
cleos new account EOS8Gv9KB3M5QmNu69j7BsGXyYQGFAiQWxK9RRmGrCTLuSUQzRE3o
cleos transfer T1HHsxQ3igveVAfbXipkWH89J6VFS5QGF6T T1BvMyqRo9BnHKi1DamjF1MwWcGT3EGfrCA "180000000.0000 EOS"

#种子轮帐户 account address: T1FwoGPJdMdCaBxiXXJYuQHQs1MnRzT9vTA
cleos wallet importkey --private-key 5KLuHULoc5W29ULdtaDUmgG9k29QngNdwKmrqFbQWV2SsKPxtV2
cleos new account EOS5h8yr8Fuz5XLVcVZL3kYQYaR8bqBJhXK4vFRVG3ThiKDt67Rsw
cleos transfer T1HHsxQ3igveVAfbXipkWH89J6VFS5QGF6T T1FwoGPJdMdCaBxiXXJYuQHQs1MnRzT9vTA "60000000.0000 EOS"

#天使轮帐户 account address: T18ZX5kBKHQWjnRfmAg1a69MwYnipZwYEPv
cleos wallet importkey --private-key 5KJBtxaU5KA3o5u59i2SRANGvh2otv8N6H4zRBWA4mpFLSkJzN3
cleos new account EOS5icRxEVxJEA6o4GbV5fN9XwkZjMVWaavBNZu7ZX7D2tVWerPmc
cleos transfer T1HHsxQ3igveVAfbXipkWH89J6VFS5QGF6T T18ZX5kBKHQWjnRfmAg1a69MwYnipZwYEPv "84000000.0000 EOS"

#私募帐户 account address: T1MHkPp5EJ2MhsztVps7MkNaEGa84rWojQp
cleos wallet importkey --private-key 5K8JvGrUkVDTukZJJmAXYxgjowNrjrxprMNumw1SEvVyjM5xP8W
cleos new account EOS66VmFxoe3oKMc1yT8CmVaoKXkLTvfnRJVyVuW9L7xwrrYV5XZp
cleos transfer T1HHsxQ3igveVAfbXipkWH89J6VFS5QGF6T T1MHkPp5EJ2MhsztVps7MkNaEGa84rWojQp "360000000.0000 EOS"

#ICO帐户 account address: T18otnQRXsMjdrMgLWp7XdbXKL8jgJvB3uQ
cleos wallet importkey --private-key 5Jk71xYbN7spuCyxu34mdMaAiUtEwCjztaqWziK9o4WAHbTNScM
cleos new account EOS5dAwSsoGDEhG5Gvy58bRoFqKxC5Yj3q33G8HPUY9CUap2U2zrg
cleos transfer T1HHsxQ3igveVAfbXipkWH89J6VFS5QGF6T T18otnQRXsMjdrMgLWp7XdbXKL8jgJvB3uQ "276000000.0000 EOS"
#./setConfigVote3.sh

sleep 1

ICO_ACCOUNT="T18otnQRXsMjdrMgLWp7XdbXKL8jgJvB3uQ"
SIMU_ACCOUNT="T1MHkPp5EJ2MhsztVps7MkNaEGa84rWojQp"
cleos producer delegatesource $SIMU_ACCOUNT $SIMU_ACCOUNT "180000000.0000 EOS" "180000000.0000 EOS"

# transfer to work node
for((i=0;i<$WORK_NODES;i++));
do
    NAME=${ProducerNameArray[i]}
    CMD="cleos transfer $ICO_ACCOUNT $NAME \"20000.0000 EOS\""
    echo $CMD
    eval $CMD 
done

sleep 1

# stake
for((i=0;i<$WORK_NODES;i++));
do
    NAME=${ProducerNameArray[i]}
    cleos producer delegatesource $NAME $NAME "10000.0000 EOS" "10000.0000 EOS"
done

sleep 1

# register as producer
for((i=0;i<$MAKER_NUM;i++));
do
    NAME=${ProducerNameArray[i]}
    cleos producer regproducer $NAME EOS5EfU2fDgHZTNwPhuoHJgKcrNJ3PbyaYMHMrgMnBpVffWjgeJjX https://$NAME.com
done

sleep 1

cleos producer listproducers

# vote
votelist=""

#ProducerNameArray[0]帐户：T1pZuev7rKTRzWDHdP9vAyK1Be2vMDBM
cleos producer voteproducers prods  $SIMU_ACCOUNT ${ProducerNameArray[0]}

for((i=0;i<$MAKER_NUM;i++));
do
    NAME=${ProducerNameArray[i]}
    CMD="cleos producer voteproducers prods $NAME $NAME"
    echo $CMD
    eval $CMD
done

cleos producer listproducers
