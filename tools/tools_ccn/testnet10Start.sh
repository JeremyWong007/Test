#！/bin/bash

source globalInfo.sh
getApplicationName $*

pkillAndWait mcp
echo "restart mcp"

function startPart1(){
    nohup ${APPLICATION_PATH_NAME} --daemon --rpc --rpc_control --network=3 --data_path=/root/ccn/localnet/test10/1 --rpc_addr=0.0.0.0 --rpc_port=8765 --port=30606 --witness --witness_account=/root/ccn/config-file/config-file-mini/0x1144B522F45265C2DFDBAEE8E324719E63A1694C.json --password=12345678 >> /dev/null 2>&1 &
    nohup ${APPLICATION_PATH_NAME} --daemon --rpc --rpc_control --network=3 --data_path=/root/ccn/localnet/test10/2 --rpc_addr=0.0.0.0 --rpc_port=8766 --port=30607 --witness --witness_account=/root/ccn/config-file/config-file-mini/0xd11c69cf2a766bee0d7b5186687e70e0ca0530db.json --password=12345678 >> /dev/null 2>&1 &
    nohup ${APPLICATION_PATH_NAME} --daemon --rpc --rpc_control --network=3 --data_path=/root/ccn/localnet/test10/3 --rpc_addr=0.0.0.0 --rpc_port=8767 --port=30608 --witness --witness_account=/root/ccn/config-file/config-file-mini/0xc086b09411e4c16b90e1b4b32a7f5d34f0f8eee4.json --password=12345678 >> /dev/null 2>&1 &
    nohup ${APPLICATION_PATH_NAME} --daemon --rpc --rpc_control --network=3 --data_path=/root/ccn/localnet/test10/4 --rpc_addr=0.0.0.0 --rpc_port=8768 --port=30609 --witness --witness_account=/root/ccn/config-file/config-file-mini/0xdb06ba6181c94d4b30ad8f3d8c29737e4222d7e7.json --password=12345678 >> /dev/null 2>&1 &
    nohup ${APPLICATION_PATH_NAME} --daemon --rpc --rpc_control --network=3 --data_path=/root/ccn/localnet/test10/5 --rpc_addr=0.0.0.0 --rpc_port=8769 --port=30610 --witness --witness_account=/root/ccn/config-file/config-file-testnet/0x5a1f0a142d687fefe59282698b78318c7fd7dcf3.json --password=12345678 >> /dev/null 2>&1 &
    nohup ${APPLICATION_PATH_NAME} --daemon --rpc --rpc_control --network=3 --data_path=/root/ccn/localnet/test10/6 --rpc_addr=0.0.0.0 --rpc_port=8770 --port=30611 --witness --witness_account=/root/ccn/config-file/config-file-testnet/0x15bcdfac7f421350ae41fa901bdb178ee7ea8e1a.json --password=12345678 >> /dev/null 2>&1 &
    nohup ${APPLICATION_PATH_NAME} --daemon --rpc --rpc_control --network=3 --data_path=/root/ccn/localnet/test10/7 --rpc_addr=0.0.0.0 --rpc_port=8771 --port=30612 --witness --witness_account=/root/ccn/config-file/config-file-testnet/0x140e5b65015a6a8c8df979ef528682d14a9855d1.json --password=12345678 >> /dev/null 2>&1 &
    nohup ${APPLICATION_PATH_NAME} --daemon --rpc --rpc_control --network=3 --data_path=/root/ccn/localnet/test10/8 --rpc_addr=0.0.0.0 --rpc_port=8772 --port=30613 --witness --witness_account=/root/ccn/config-file/config-file-testnet/0x777dbf4dff1dcb7165ebb4d8dc3590b6dba05868.json --password=12345678 >> /dev/null 2>&1 &
    nohup ${APPLICATION_PATH_NAME} --daemon --rpc --rpc_control --network=3 --data_path=/root/ccn/localnet/test10/9 --rpc_addr=0.0.0.0 --rpc_port=8773 --port=30614 --witness --witness_account=/root/ccn/config-file/config-file-testnet/0x6900e0e415284ee2d34bffdfa3800d25dda1f789.json --password=12345678 >> /dev/null 2>&1 &
    nohup ${APPLICATION_PATH_NAME} --daemon --rpc --rpc_control --network=3 --data_path=/root/ccn/localnet/test10/10 --rpc_addr=0.0.0.0 --rpc_port=8774 --port=30615 --witness --witness_account=/root/ccn/config-file/config-file-testnet/0x23936f76f1225fdd6147646fa9082dabadac469f.json --password=12345678 >> /dev/null 2>&1 &
}

function startPart2(){
    nohup ${APPLICATION_PATH_NAME} --daemon --rpc --rpc_control --network=3 --data_path=/root/ccn/localnet/test10/11 --rpc_addr=0.0.0.0 --rpc_port=8775 --port=30616 --witness --witness_account=/root/ccn/config-file/config-file-testnet/0xa55bb0fb21612faf9e182f4a8c90bd1bf941c164.json --password=12345678 >> /dev/null 2>&1 &
    nohup ${APPLICATION_PATH_NAME} --daemon --rpc --rpc_control --network=3 --data_path=/root/ccn/localnet/test10/12 --rpc_addr=0.0.0.0 --rpc_port=8776 --port=30617 --witness --witness_account=/root/ccn/config-file/config-file-testnet/0xb98e786e0e399842196bc9d3c7dab81dcceac2c2.json --password=12345678 >> /dev/null 2>&1 &
    nohup ${APPLICATION_PATH_NAME} --daemon --rpc --rpc_control --network=3 --data_path=/root/ccn/localnet/test10/13 --rpc_addr=0.0.0.0 --rpc_port=8777 --port=30618 --witness --witness_account=/root/ccn/config-file/config-file-testnet/0xc3f3e6c0696ffae1f7101c18b9b43bff4cb7f42f.json --password=12345678 >> /dev/null 2>&1 &
    nohup ${APPLICATION_PATH_NAME} --daemon --rpc --rpc_control --network=3 --data_path=/root/ccn/localnet/test10/14 --rpc_addr=0.0.0.0 --rpc_port=8778 --port=30619 --witness --witness_account=/root/ccn/config-file/config-file-testnet/0xc2499e9b66d7f4081bb5915dfddb386c53228fa4.json --password=12345678 >> /dev/null 2>&1 &
    nohup ${APPLICATION_PATH_NAME} --daemon --rpc --rpc_control --network=3 --data_path=/root/ccn/localnet/test10/15 --rpc_addr=0.0.0.0 --rpc_port=8779 --port=30620 --witness --witness_account=/root/ccn/config-file/config-file-testnet/0xe9c1b8c09a32ed572441024953c591ae28c87380.json --password=12345678 >> /dev/null 2>&1 &
    nohup ${APPLICATION_PATH_NAME} --daemon --rpc --rpc_control --network=3 --data_path=/root/ccn/localnet/test10/16 --rpc_addr=0.0.0.0 --rpc_port=8780 --port=30621 --witness --witness_account=/root/ccn/config-file/config-file-testnet/0xed1f63367fd7af0310c5b46aeca14680bb1d270b.json --password=12345678 >> /dev/null 2>&1 &
    nohup ${APPLICATION_PATH_NAME} --daemon --rpc --rpc_control --network=3 --data_path=/root/ccn/localnet/test10/17 --rpc_addr=0.0.0.0 --rpc_port=8781 --port=30622 --witness --witness_account=/root/ccn/config-file/config-file-testnet/0xf9197377df0e45094f6fa555325a085c0c9c0afe.json --password=12345678 >> /dev/null 2>&1 &
    nohup ${APPLICATION_PATH_NAME} --daemon --rpc --rpc_control --network=3 --data_path=/root/ccn/localnet/test10/18 --rpc_addr=0.0.0.0 --rpc_port=8782 --port=30623 --witness --witness_account=/root/ccn/config-file/config-file-testnet/0xfd708ba83a168077c9999d98e3b81c1cc975bdef.json --password=12345678 >> /dev/null 2>&1 &
    nohup ${APPLICATION_PATH_NAME} --daemon --rpc --rpc_control --network=3 --data_path=/root/ccn/localnet/test10/19 --rpc_addr=0.0.0.0 --rpc_port=8783 --port=30624 --witness --witness_account=/root/ccn/config-file/config-file-testnet/part2/0x3ef22091fcf552b4e9371608e7066dcbbd5fec15.json --password=12345678 >> /dev/null 2>&1 &
    nohup ${APPLICATION_PATH_NAME} --daemon --rpc --rpc_control --network=3 --data_path=/root/ccn/localnet/test10/20 --rpc_addr=0.0.0.0 --rpc_port=8784 --port=30625 --witness --witness_account=/root/ccn/config-file/config-file-testnet/part2/0x3fd605e394b6c61a2ec2538ac0f779e2968abd43.json --password=12345678 >> /dev/null 2>&1 &
}

function startPart3(){
    nohup ${APPLICATION_PATH_NAME} --daemon --rpc --rpc_control --network=3 --data_path=/root/ccn/localnet/test10/21 --rpc_addr=0.0.0.0 --rpc_port=8785 --port=30626 --witness --witness_account=/root/ccn/config-file/config-file-testnet/part2/0x4deb824c0e6035f97654aa231a8bf2b6e988b7e5.json --password=12345678 >> /dev/null 2>&1 &
    nohup ${APPLICATION_PATH_NAME} --daemon --rpc --rpc_control --network=3 --data_path=/root/ccn/localnet/test10/22 --rpc_addr=0.0.0.0 --rpc_port=8786 --port=30627 --witness --witness_account=/root/ccn/config-file/config-file-testnet/part2/0x9ac7ea2b68c7ebd821d0e6f1f73c8678ade7ea4d.json --password=12345678 >> /dev/null 2>&1 &
    nohup ${APPLICATION_PATH_NAME} --daemon --rpc --rpc_control --network=3 --data_path=/root/ccn/localnet/test10/23 --rpc_addr=0.0.0.0 --rpc_port=8787 --port=30628 --witness --witness_account=/root/ccn/config-file/config-file-testnet/part2/0x15986059d08c85c7c8b66ec9bba06518e1982e25.json --password=12345678 >> /dev/null 2>&1 &
    nohup ${APPLICATION_PATH_NAME} --daemon --rpc --rpc_control --network=3 --data_path=/root/ccn/localnet/test10/24 --rpc_addr=0.0.0.0 --rpc_port=8788 --port=30629 --witness --witness_account=/root/ccn/config-file/config-file-testnet/part2/0xae0bf9072b885722f3c2eae8edebed3b461ea19a.json --password=12345678 >> /dev/null 2>&1 &
    nohup ${APPLICATION_PATH_NAME} --daemon --rpc --rpc_control --network=3 --data_path=/root/ccn/localnet/test10/25 --rpc_addr=0.0.0.0 --rpc_port=8789 --port=30630 --witness --witness_account=/root/ccn/config-file/config-file-testnet/part2/0xb3d132b42dc41de85aa13bcf3047cd04e85c435a.json --password=12345678 >> /dev/null 2>&1 &
    nohup ${APPLICATION_PATH_NAME} --daemon --rpc --rpc_control --network=3 --data_path=/root/ccn/localnet/test10/26 --rpc_addr=0.0.0.0 --rpc_port=8790 --port=30631 --witness --witness_account=/root/ccn/config-file/config-file-testnet/part2/0xbb1f86e871852225163c3c0c15fcbe4357c2667e.json --password=12345678 >> /dev/null 2>&1 &
    nohup ${APPLICATION_PATH_NAME} --daemon --rpc --rpc_control --network=3 --data_path=/root/ccn/localnet/test10/27 --rpc_addr=0.0.0.0 --rpc_port=8791 --port=30632 --witness --witness_account=/root/ccn/config-file/config-file-testnet/part2/0xdb61485d67b173efdcdcdb3e68be5b8c68e7adde.json --password=12345678 >> /dev/null 2>&1 &
    nohup ${APPLICATION_PATH_NAME} --daemon --rpc --rpc_control --network=3 --data_path=/root/ccn/localnet/test10/28 --rpc_addr=0.0.0.0 --rpc_port=8792 --port=30633 --witness --witness_account=/root/ccn/config-file/config-file-testnet/part2/0xde4dd6efe9bd7ba5ad3525098946cc19571eba1c.json --password=12345678 >> /dev/null 2>&1 &
}

if [ "$#" -le "1" ]; then
{
    echo "run all"
    startPart1
    startPart2
    #startPart3
}
elif [ "$2" == "part1" ]; then
{
    echo "run part1"
    startPart1
}
elif [ "$2" == "part2" ]; then
{
    echo "run part2"
    startPart2
}
else
{
    echo "Params are wrong!"
}
fi