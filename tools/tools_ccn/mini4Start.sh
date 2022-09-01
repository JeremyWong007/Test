#！/bin/bash

source globalInfo.sh
getApplicationName $*

pkillAndWait $APPLICATION_NAME
echo "restart $APPLICATION_NAME"

if [ $APPLICATION_NAME == "mcp" ]; then
{
    DATA_PATH="/root/ccn/localnet/mini4/"
    RPC_PORT="87"
    P2P_PORT="306"
}
elif [ $APPLICATION_NAME == "test1" ]; then
{
    DATA_PATH="/root/ccn/localnet/mini4_test1/"
    RPC_PORT="88"
    P2P_PORT="307"
}
else
{
    echo "$APPLICATION_NAME hasn't set."
    return;
}
fi

nohup ${APPLICATION_PATH_NAME} --daemon --rpc --rpc_control --network=4 --data_path=${DATA_PATH}1 --rpc_addr=0.0.0.0 --rpc_port=${RPC_PORT}65 --port=${P2P_PORT}06 --witness --witness_account=/root/ccn/config-file/config-file-new/0x1144B522F45265C2DFDBAEE8E324719E63A1694C.json --password=12345678 >> /dev/null 2>&1 &
nohup ${APPLICATION_PATH_NAME} --daemon --rpc --rpc_control --network=4 --data_path=${DATA_PATH}2 --rpc_addr=0.0.0.0 --rpc_port=${RPC_PORT}66 --port=${P2P_PORT}07 --witness --witness_account=/root/ccn/config-file/config-file-new/0x1895ac1edc15389b905bb19537eb0c5b33d8c77a.json --password=12345678 >> /dev/null 2>&1 &
nohup ${APPLICATION_PATH_NAME} --daemon --rpc --rpc_control --network=4 --data_path=${DATA_PATH}3 --rpc_addr=0.0.0.0 --rpc_port=${RPC_PORT}67 --port=${P2P_PORT}08 --witness --witness_account=/root/ccn/config-file/config-file-new/0x329e6b5b8e59fc73d892958b2ff6a89474e3d067.json --password=12345678 >> /dev/null 2>&1 &
nohup ${APPLICATION_PATH_NAME} --daemon --rpc --rpc_control --network=4 --data_path=${DATA_PATH}4 --rpc_addr=0.0.0.0 --rpc_port=${RPC_PORT}68 --port=${P2P_PORT}09 --witness --witness_account=/root/ccn/config-file/config-file-new/0x49a1b41e8ccb704f5c069ef89b08cd33f764e9b3.json --password=12345678 >> /dev/null 2>&1 &