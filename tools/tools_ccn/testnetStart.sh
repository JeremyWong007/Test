#！/bin/bash

source globalInfo.sh
getApplicationName $*

pkillAndWait mcp
echo "restart mcp"

function startPart1(){
    nohup ${APPLICATION_NAME} --daemon --rpc --rpc_control --network=3 --data_path=/root/ccn/localnet/testmode/1 --rpc_addr=0.0.0.0 --rpc_port=8765 --port=30606 --witness --witness_account=/root/ccn/config-file/config-file-new/0xf0821dc4ba9419b865aa412170377ca3b44cdb58.json --password=12345678 >> /dev/null 2>&1 &
    nohup ${APPLICATION_NAME} --daemon --rpc --rpc_control --network=3 --data_path=/root/ccn/localnet/testmode/2 --rpc_addr=0.0.0.0 --rpc_port=8766 --port=30607 --witness --witness_account=/root/ccn/config-file/config-file-new/0x05174fa7ab39a36391b17850a2db9afdcf57190e.json --password=12345678 >> /dev/null 2>&1 &
    nohup ${APPLICATION_NAME} --daemon --rpc --rpc_control --network=3 --data_path=/root/ccn/localnet/testmode/3 --rpc_addr=0.0.0.0 --rpc_port=8767 --port=30608 --witness --witness_account=/root/ccn/config-file/config-file-new/0x1895ac1edc15389b905bb19537eb0c5b33d8c77a.json --password=12345678 >> /dev/null 2>&1 &
    nohup ${APPLICATION_NAME} --daemon --rpc --rpc_control --network=3 --data_path=/root/ccn/localnet/testmode/4 --rpc_addr=0.0.0.0 --rpc_port=8768 --port=30609 --witness --witness_account=/root/ccn/config-file/config-file-new/0x329e6b5b8e59fc73d892958b2ff6a89474e3d067.json --password=12345678 >> /dev/null 2>&1 &
    nohup ${APPLICATION_NAME} --daemon --rpc --rpc_control --network=3 --data_path=/root/ccn/localnet/testmode/5 --rpc_addr=0.0.0.0 --rpc_port=8769 --port=30610 --witness --witness_account=/root/ccn/config-file/config-file-new/0x49a1b41e8ccb704f5c069ef89b08cd33f764e9b3.json --password=12345678 >> /dev/null 2>&1 &
    nohup ${APPLICATION_NAME} --daemon --rpc --rpc_control --network=3 --data_path=/root/ccn/localnet/testmode/6 --rpc_addr=0.0.0.0 --rpc_port=8770 --port=30611 --witness --witness_account=/root/ccn/config-file/config-file-new/0x827cce78dc6ec7051f2d7bb9e7adaefba7ca3248.json --password=12345678 >> /dev/null 2>&1 &
    nohup ${APPLICATION_NAME} --daemon --rpc --rpc_control --network=3 --data_path=/root/ccn/localnet/testmode/7 --rpc_addr=0.0.0.0 --rpc_port=8771 --port=30612 --witness --witness_account=/root/ccn/config-file/config-file-new/0x918d3fe1dbff02fc7521d4a04b50017ce1a7c2ea.json --password=12345678 >> /dev/null 2>&1 &
    nohup ${APPLICATION_NAME} --daemon --rpc --rpc_control --network=3 --data_path=/root/ccn/localnet/testmode/8 --rpc_addr=0.0.0.0 --rpc_port=8772 --port=30613 --witness --witness_account=/root/ccn/config-file/config-file-new/0x929f336edb0a39ad5532a462d4a84e1546c5e5de.json --password=12345678 >> /dev/null 2>&1 &
    nohup ${APPLICATION_NAME} --daemon --rpc --rpc_control --network=3 --data_path=/root/ccn/localnet/testmode/9 --rpc_addr=0.0.0.0 --rpc_port=8773 --port=30614 --witness --witness_account=/root/ccn/config-file/config-file-new/0xa11b98c54d4189adda8eda97e13c214fedaf0a0f.json --password=12345678 >> /dev/null 2>&1 &
    nohup ${APPLICATION_NAME} --daemon --rpc --rpc_control --network=3 --data_path=/root/ccn/localnet/testmode/10 --rpc_addr=0.0.0.0 --rpc_port=8774 --port=30615 --witness --witness_account=/root/ccn/config-file/config-file-new/0xa65ec5c65031d668094cb1b81bb8253ea64a23d7.json --password=12345678 >> /dev/null 2>&1 &
}

function startPart2(){
    nohup ${APPLICATION_NAME} --daemon --rpc --rpc_control --network=3 --data_path=/root/ccn/localnet/testmode/11 --rpc_addr=0.0.0.0 --rpc_port=8775 --port=30616 --witness --witness_account=/root/ccn/config-file/config-file-new/0xba618c1e3e90d16e6c15d92ed198780dc4ad39c2.json --password=12345678 >> /dev/null 2>&1 &
    nohup ${APPLICATION_NAME} --daemon --rpc --rpc_control --network=3 --data_path=/root/ccn/localnet/testmode/12 --rpc_addr=0.0.0.0 --rpc_port=8776 --port=30617 --witness --witness_account=/root/ccn/config-file/config-file-new/0xc2cf7b9eb048c34c2b00175a884543366bbcd029.json --password=12345678 >> /dev/null 2>&1 &
    nohup ${APPLICATION_NAME} --daemon --rpc --rpc_control --network=3 --data_path=/root/ccn/localnet/testmode/13 --rpc_addr=0.0.0.0 --rpc_port=8777 --port=30618 --witness --witness_account=/root/ccn/config-file/config-file-new/0xc543a3868f3613eecd109761f71e31832ecf51ba.json --password=12345678 >> /dev/null 2>&1 &
    nohup ${APPLICATION_NAME} --daemon --rpc --rpc_control --network=3 --data_path=/root/ccn/localnet/testmode/14 --rpc_addr=0.0.0.0 --rpc_port=8778 --port=30619 --witness --witness_account=/root/ccn/config-file/config-file-new/0xdab8a5fb82eb24ad321751bb2dd8e4cc9a4e45e5.json --password=12345678 >> /dev/null 2>&1 &
    nohup ${APPLICATION_NAME} --daemon --rpc --rpc_control --network=3 --data_path=/root/ccn/localnet/testmode/15 --rpc_addr=0.0.0.0 --rpc_port=8779 --port=30620 --witness --witness_account=/root/ccn/config-file/config-file-new/0x1144B522F45265C2DFDBAEE8E324719E63A1694C.json --password=12345678 >> /dev/null 2>&1 &
    nohup ${APPLICATION_NAME} --daemon --rpc --rpc_control --network=3 --data_path=/root/ccn/localnet/testmode/16 --rpc_addr=0.0.0.0 --rpc_port=8780 --port=30621 --witness --witness_account=/root/ccn/config-file/config-file-new/part2/0x088415bbf9b7dfe93f2231fa5dd527a04c874845.json --password=12345678 >> /dev/null 2>&1 &
    nohup ${APPLICATION_NAME} --daemon --rpc --rpc_control --network=3 --data_path=/root/ccn/localnet/testmode/17 --rpc_addr=0.0.0.0 --rpc_port=8781 --port=30622 --witness --witness_account=/root/ccn/config-file/config-file-new/part2/0x4158f69f4499f9c5b7d5744ca2020741fd9fc0bc.json --password=12345678 >> /dev/null 2>&1 &
    nohup ${APPLICATION_NAME} --daemon --rpc --rpc_control --network=3 --data_path=/root/ccn/localnet/testmode/18 --rpc_addr=0.0.0.0 --rpc_port=8782 --port=30623 --witness --witness_account=/root/ccn/config-file/config-file-new/part2/0x820a7d4e3d816eabb6e2a5bfe6e5eac60c39c406.json --password=12345678 >> /dev/null 2>&1 &
    nohup ${APPLICATION_NAME} --daemon --rpc --rpc_control --network=3 --data_path=/root/ccn/localnet/testmode/19 --rpc_addr=0.0.0.0 --rpc_port=8783 --port=30624 --witness --witness_account=/root/ccn/config-file/config-file-new/part2/0x8b5c7ce9fbaed1bebb3043416684bc6913962670.json --password=12345678 >> /dev/null 2>&1 &
    nohup ${APPLICATION_NAME} --daemon --rpc --rpc_control --network=3 --data_path=/root/ccn/localnet/testmode/20 --rpc_addr=0.0.0.0 --rpc_port=8784 --port=30625 --witness --witness_account=/root/ccn/config-file/config-file-new/part2/0xb5575c29ba308cac3ff476485e87e4b4ef604f9b.json --password=12345678 >> /dev/null 2>&1 &
}

function startPart3(){
    nohup ${APPLICATION_NAME} --daemon --rpc --rpc_control --network=3 --data_path=/root/ccn/localnet/testmode/21 --rpc_addr=0.0.0.0 --rpc_port=8785 --port=30626 --witness --witness_account=/root/ccn/config-file/config-file-new/0x4deb824c0e6035f97654aa231a8bf2b6e988b7e5.json --password=12345678 >> /dev/null 2>&1 &
    nohup ${APPLICATION_NAME} --daemon --rpc --rpc_control --network=3 --data_path=/root/ccn/localnet/testmode/22 --rpc_addr=0.0.0.0 --rpc_port=8786 --port=30627 --witness --witness_account=/root/ccn/config-file/config-file-new/0x9ac7ea2b68c7ebd821d0e6f1f73c8678ade7ea4d.json --password=12345678 >> /dev/null 2>&1 &
    nohup ${APPLICATION_NAME} --daemon --rpc --rpc_control --network=3 --data_path=/root/ccn/localnet/testmode/23 --rpc_addr=0.0.0.0 --rpc_port=8787 --port=30628 --witness --witness_account=/root/ccn/config-file/config-file-new/0x15986059d08c85c7c8b66ec9bba06518e1982e25.json --password=12345678 >> /dev/null 2>&1 &
    nohup ${APPLICATION_NAME} --daemon --rpc --rpc_control --network=3 --data_path=/root/ccn/localnet/testmode/24 --rpc_addr=0.0.0.0 --rpc_port=8788 --port=30629 --witness --witness_account=/root/ccn/config-file/config-file-new/0xae0bf9072b885722f3c2eae8edebed3b461ea19a.json --password=12345678 >> /dev/null 2>&1 &
    nohup ${APPLICATION_NAME} --daemon --rpc --rpc_control --network=3 --data_path=/root/ccn/localnet/testmode/25 --rpc_addr=0.0.0.0 --rpc_port=8789 --port=30630 --witness --witness_account=/root/ccn/config-file/config-file-new/0xb3d132b42dc41de85aa13bcf3047cd04e85c435a.json --password=12345678 >> /dev/null 2>&1 &
    nohup ${APPLICATION_NAME} --daemon --rpc --rpc_control --network=3 --data_path=/root/ccn/localnet/testmode/26 --rpc_addr=0.0.0.0 --rpc_port=8790 --port=30631 --witness --witness_account=/root/ccn/config-file/config-file-new/0xbb1f86e871852225163c3c0c15fcbe4357c2667e.json --password=12345678 >> /dev/null 2>&1 &
    nohup ${APPLICATION_NAME} --daemon --rpc --rpc_control --network=3 --data_path=/root/ccn/localnet/testmode/27 --rpc_addr=0.0.0.0 --rpc_port=8791 --port=30632 --witness --witness_account=/root/ccn/config-file/config-file-new/0xdb61485d67b173efdcdcdb3e68be5b8c68e7adde.json --password=12345678 >> /dev/null 2>&1 &
    nohup ${APPLICATION_NAME} --daemon --rpc --rpc_control --network=3 --data_path=/root/ccn/localnet/testmode/28 --rpc_addr=0.0.0.0 --rpc_port=8792 --port=30633 --witness --witness_account=/root/ccn/config-file/config-file-new/0xde4dd6efe9bd7ba5ad3525098946cc19571eba1c.json --password=12345678 >> /dev/null 2>&1 &
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