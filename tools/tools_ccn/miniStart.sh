#！/bin/bash

source globalInfo.sh
getApplicationName $*

pkillAndWait mcp
echo "restart mcp"

nohup ${APPLICATION_PATH_NAME} --daemon --rpc --rpc_control --network=4 --data_path=/root/ccn/localnet/mcp-mini --rpc_addr=0.0.0.0 --rpc_port=8765  --witness --witness_account=/root/ccn/config-file/config-file-new/0x1144B522F45265C2DFDBAEE8E324719E63A1694C.json --password=12345678 >> /dev/null 2>&1 &