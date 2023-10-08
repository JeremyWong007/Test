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
MAKER_NUM=50 #生产者数量，要求（<=WORK_NODES）

GENESIS_ACCOUNT="eosio"
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

killall nodeos
rm -rf /tmp/rctest/*

# unlock wallet
./unlock.sh

# import private keys
for((i=0;i<$WORK_NODES;i++));
do
    PRIV_KEY=${private_keys[i]}
    cleos wallet import --private-key $PRIV_KEY
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
--genesis-json "./genesis.json" \
--logconf=./logging.json \
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
    --genesis-json "./genesis.json" \
    --logconf=./logging.json \
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
./setConfigNormal.sh

sleep 1

# create all account and get name
echo "create all account and get name:"
for((i=0;i<$WORK_NODES;i++));
do
    PUB_KEY=${public_keys[i]}
    ProducerName=${ProducerNameArray[i]}
    cleos system newaccount eosio --transfer ${ProducerName} ${PUB_KEY} --stake-net "100.0000 RC" --stake-cpu "100.0000 RC" --buy-ram-kbytes 8
    echo $i "ProducerName="$ProducerName
done



# transfer to work node
for((i=0;i<$WORK_NODES;i++));
do
    NAME=${ProducerNameArray[i]}
    CMD="cleos transfer eosio $NAME \"20000.0000 RC\""
    echo $CMD
    eval $CMD 
done

sleep 1

# stake
for((i=0;i<$WORK_NODES;i++));
do
    NAME=${ProducerNameArray[i]}
    #cleos system delegatebw accountnum11 accountnum11 
    cleos system delegatebw $NAME $NAME "10000.0000 RC" "10000.0000 RC"
done

sleep 1

# register as producer
for((i=0;i<$MAKER_NUM;i++));
do
    NAME=${ProducerNameArray[i]}
    cleos system regproducer $NAME EOS5EfU2fDgHZTNwPhuoHJgKcrNJ3PbyaYMHMrgMnBpVffWjgeJjX https://$NAME.com
done

sleep 1

cleos producer listproducers

# vote
votelist=""

#ProducerNameArray[0]帐户：T1pZuev7rKTRzWDHdP9vAyK1Be2vMDBM
#cleos system voteproducer prods accountnum11 accountnum11 accountnum12 accountnum13
#cleos system voteproducer prods  $SIMU_ACCOUNT ${ProducerNameArray[0]}

for((i=0;i<$MAKER_NUM;i++));
do
    NAME=${ProducerNameArray[i]}
    CMD="cleos system voteproducer prods $NAME $NAME"
    echo $CMD
    eval $CMD
done

cleos system buyram eosio eosio "200 RC"
cleos system delegatebw eosio eosio "100000000.0000 RC" "100000000.0000 RC"
cleos system voteproducer prods eosio ${ProducerNameArray[0]}

cleos system listproducers
