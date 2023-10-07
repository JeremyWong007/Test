#!/bin/bash

#set -x

if [ $1 != "first" ]; then
    if [ $# != 2 ]; then
        exit -1
    fi
    WORK_NODES_START=$1 #节点起始编号
    WORK_NODES_END=$2 #节点结束编号
    MAKER_NUM_START=$1 #生产者起始编号
    MAKER_NUM_END=$2 #生产者结束编号
else
    WORK_NODES_START=0
    WORK_NODES_END=0
    MAKER_NUM_START=0
    MAKER_NUM_END=0
fi

GENESIS_SERVER_IP_PORT="192.168.0.230:9510"
#GENESIS_SERVER_IP_PORT="35.76.107.8:9510"

#公钥 EOS8mUftJXepGzdQ2TaCduNuSPAfXJHf22uex4u41ab1EVv9EAhWt
#私钥 5K7EYY3j1YY14TSFVfqgtbWbrw3FA8BUUnSyFGgwHi8Uy61wU1o
FIRST_ACCOUNT="T12BSJuiScm4BkzJhafXPek6Uy2kxmkPm" #无需创建

source globalInfo.sh
./importKey.sh


if [ "${#private_keys2[@]}" -ne "${#public_keys2[@]}" ]; then
    echo "public key and private key count not equal"
    exit 0
fi

if [ "$WORK_NODES_END" -gt "${#private_keys2[@]}" ]; then
    echo "work node is too big"
    exit 0
fi

ProducerNameArray=()

# unlock wallet
#cleos wallet unlock --password $WALLET_PWD
./unlock.sh

# import private keys
for((i=$WORK_NODES_START;i<$WORK_NODES_END;i++));
do
    PRIV_KEY=${private_keys2[i]}
    cleos wallet importkey --private-key $PRIV_KEY
done

# start first node
HTTP_LISTEN_PORT=8888
P2P_LISTEN_PORT=9510
P2P_LISTEN_PORT_TO=`expr 9510 + 1`
DATADIR="/tmp/rctest/first"
PROVIDER="EOS5EfU2fDgHZTNwPhuoHJgKcrNJ3PbyaYMHMrgMnBpVffWjgeJjX=KEY:5HxK6mfoNr1pbnbYs1AmsKjavJQaoxiNVUdeJD6ZPFZkQvGcZVM"
NAME=$FIRST_ACCOUNT

if [ $1 == "first" ];
then
    killall nodeos
    rm -rf /tmp/rctest/*
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
    --p2p-peer-address $GENESIS_SERVER_IP_PORT \
    --producer-name $NAME \
    --signature-provider $PROVIDER \
    >> $DATADIR"/nodeos.log" 2>&1 & \
    echo $! > $DATADIR"/eosd.pid" "

    echo $CMD
    eval $CMD
    exit 0
fi
sleep 1

# create all account and get name
echo "create all account and get name:"
for((i=$WORK_NODES_START;i<$WORK_NODES_END;i++));
do
    PUB_KEY=${public_keys2[i]}
    RSP=`cleos new account $PUB_KEY`
    RESULT=`echo $RSP | awk -F 'account address: ' '{print $2}' `
    # if is empty, exit
    ProducerNameArray[i]=$RESULT
    echo $i $RESULT
done

# start work nodes
for((i=$WORK_NODES_START;i<$WORK_NODES_END;i++));
do
    HTTP_LISTEN_PORT=`expr 8888 + $i + 1`
    P2P_LISTEN_PORT=`expr 9510 + $i + 1`
    if [ $i == $WORK_NODES_START ];
    then
        P2P_LISTEN_PORT_TO=9510
    else
        P2P_LISTEN_PORT_TO=`expr $P2P_LISTEN_PORT - 1`
    fi
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

ICO_ACCOUNT="T18otnQRXsMjdrMgLWp7XdbXKL8jgJvB3uQ"

# transfer to work node
for((i=$WORK_NODES_START;i<$WORK_NODES_END;i++));
do
    NAME=${ProducerNameArray[i]}
    CMD="cleos transfer $ICO_ACCOUNT $NAME \"20000.0000 EOS\""
    echo $CMD
    eval $CMD 
done

sleep 1

# stake
for((i=$WORK_NODES_START;i<$WORK_NODES_END;i++));
do
    NAME=${ProducerNameArray[i]}
    cleos producer delegatesource $NAME $NAME "10000.0000 EOS" "10000.0000 EOS"
done

sleep 1

# register as producer
for((i=$MAKER_NUM_START;i<$MAKER_NUM_END;i++));
do
    NAME=${ProducerNameArray[i]}
    cleos producer regproducer $NAME EOS5EfU2fDgHZTNwPhuoHJgKcrNJ3PbyaYMHMrgMnBpVffWjgeJjX https://$NAME.com
done

sleep 1

cleos producer listproducers

# vote
votelist=""

for((i=$MAKER_NUM_START;i<$MAKER_NUM_END;i++));
do
    NAME=${ProducerNameArray[i]}
    CMD="cleos producer voteproducers prods $NAME $NAME"
    echo $CMD
    eval $CMD
done

cleos producer listproducers
