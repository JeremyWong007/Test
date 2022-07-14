#！/bin/bash

source globalInfo.sh
getApplicationName $*

pkillAndWait mcp
echo "restart mcp"

nohup ${APPLICATION_NAME} --daemon --rpc --rpc_control --network=4 --data_path=/root/ccn/localnet/mini4/1 --rpc_addr=0.0.0.0 --rpc_port=8765 --port=30606 --witness --witness_account=/root/ccn/config-file/config-file-mini/0x1144B522F45265C2DFDBAEE8E324719E63A1694C.json --password=12345678 >> /dev/null 2>&1 &
nohup ${APPLICATION_NAME} --daemon --rpc --rpc_control --network=4 --data_path=/root/ccn/localnet/mini4/2 --rpc_addr=0.0.0.0 --rpc_port=8766 --port=30607 --witness --witness_account=/root/ccn/config-file/config-file-mini/0xd11c69cf2a766bee0d7b5186687e70e0ca0530db.json --password=12345678 >> /dev/null 2>&1 &
nohup ${APPLICATION_NAME} --daemon --rpc --rpc_control --network=4 --data_path=/root/ccn/localnet/mini4/3 --rpc_addr=0.0.0.0 --rpc_port=8767 --port=30608 --witness --witness_account=/root/ccn/config-file/config-file-mini/0xc086b09411e4c16b90e1b4b32a7f5d34f0f8eee4.json --password=12345678 >> /dev/null 2>&1 &
nohup ${APPLICATION_NAME} --daemon --rpc --rpc_control --network=4 --data_path=/root/ccn/localnet/mini4/4 --rpc_addr=0.0.0.0 --rpc_port=8768 --port=30609 --witness --witness_account=/root/ccn/config-file/config-file-mini/0xdb06ba6181c94d4b30ad8f3d8c29737e4222d7e7.json --password=12345678 >> /dev/null 2>&1 &