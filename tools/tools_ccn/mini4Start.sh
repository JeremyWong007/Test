#！/bin/bash

source globalInfo.sh
getApplicationName $*

pkillAndWait mcp
echo "restart mcp"

nohup ${APPLICATION_PATH_NAME} --daemon --rpc --rpc_control --network=4 --data_path=/root/ccn/localnet/mini4/1 --rpc_addr=0.0.0.0 --rpc_port=8765 --port=30606 --witness --witness_account=/root/ccn/config-file/config-file-new/0x1144B522F45265C2DFDBAEE8E324719E63A1694C.json --password=12345678 >> /dev/null 2>&1 &
nohup ${APPLICATION_PATH_NAME} --daemon --rpc --rpc_control --network=4 --data_path=/root/ccn/localnet/mini4/2 --rpc_addr=0.0.0.0 --rpc_port=8766 --port=30607 --witness --witness_account=/root/ccn/config-file/config-file-new/0x1895ac1edc15389b905bb19537eb0c5b33d8c77a.json --password=12345678 >> /dev/null 2>&1 &
nohup ${APPLICATION_PATH_NAME} --daemon --rpc --rpc_control --network=4 --data_path=/root/ccn/localnet/mini4/3 --rpc_addr=0.0.0.0 --rpc_port=8767 --port=30608 --witness --witness_account=/root/ccn/config-file/config-file-new/0x329e6b5b8e59fc73d892958b2ff6a89474e3d067.json --password=12345678 >> /dev/null 2>&1 &
nohup ${APPLICATION_PATH_NAME} --daemon --rpc --rpc_control --network=4 --data_path=/root/ccn/localnet/mini4/4 --rpc_addr=0.0.0.0 --rpc_port=8768 --port=30609 --witness --witness_account=/root/ccn/config-file/config-file-new/0x49a1b41e8ccb704f5c069ef89b08cd33f764e9b3.json --password=12345678 >> /dev/null 2>&1 &