#！/bin/bash

source globalInfo.sh
getApplicationName $*

pkillAndWait $APPLICATION_NAME
echo "restart $APPLICATION_NAME"

if [ $APPLICATION_NAME == "mcp" ]; then
{
    DATA_PATH="/root/ccn/localnet/testmode/"
    RPC_PORT="87"
    P2P_PORT="306"
}
elif [ $APPLICATION_NAME == "test1" ]; then
{
    DATA_PATH="/root/ccn/localnet/testmode1/"
    RPC_PORT="88"
    P2P_PORT="307"
}
else
{
    echo "$APPLICATION_NAME hasn't set."
    return;
}
fi

function startPart1(){
    nohup ${APPLICATION_PATH_NAME} --daemon --rpc --rpc_control --network=3 --data_path=${DATA_PATH}1 --rpc_addr=0.0.0.0 --rpc_port=${RPC_PORT}65 --port=${P2P_PORT}06 --witness --witness_account=/root/ccn/config-file/config-file-new/0xf0821dc4ba9419b865aa412170377ca3b44cdb58.json --password=12345678 >> /dev/null 2>&1 &
    nohup ${APPLICATION_PATH_NAME} --daemon --rpc --rpc_control --network=3 --data_path=${DATA_PATH}2 --rpc_addr=0.0.0.0 --rpc_port=${RPC_PORT}66 --port=${P2P_PORT}07 --witness --witness_account=/root/ccn/config-file/config-file-new/0x05174fa7ab39a36391b17850a2db9afdcf57190e.json --password=12345678 >> /dev/null 2>&1 &
    nohup ${APPLICATION_PATH_NAME} --daemon --rpc --rpc_control --network=3 --data_path=${DATA_PATH}3 --rpc_addr=0.0.0.0 --rpc_port=${RPC_PORT}67 --port=${P2P_PORT}08 --witness --witness_account=/root/ccn/config-file/config-file-new/0x1895ac1edc15389b905bb19537eb0c5b33d8c77a.json --password=12345678 >> /dev/null 2>&1 &
    nohup ${APPLICATION_PATH_NAME} --daemon --rpc --rpc_control --network=3 --data_path=${DATA_PATH}4 --rpc_addr=0.0.0.0 --rpc_port=${RPC_PORT}68 --port=${P2P_PORT}09 --witness --witness_account=/root/ccn/config-file/config-file-new/0x329e6b5b8e59fc73d892958b2ff6a89474e3d067.json --password=12345678 >> /dev/null 2>&1 &
    nohup ${APPLICATION_PATH_NAME} --daemon --rpc --rpc_control --network=3 --data_path=${DATA_PATH}5 --rpc_addr=0.0.0.0 --rpc_port=${RPC_PORT}69 --port=${P2P_PORT}10 --witness --witness_account=/root/ccn/config-file/config-file-new/0x49a1b41e8ccb704f5c069ef89b08cd33f764e9b3.json --password=12345678 >> /dev/null 2>&1 &
    nohup ${APPLICATION_PATH_NAME} --daemon --rpc --rpc_control --network=3 --data_path=${DATA_PATH}6 --rpc_addr=0.0.0.0 --rpc_port=${RPC_PORT}70 --port=${P2P_PORT}11 --witness --witness_account=/root/ccn/config-file/config-file-new/0x827cce78dc6ec7051f2d7bb9e7adaefba7ca3248.json --password=12345678 >> /dev/null 2>&1 &
    nohup ${APPLICATION_PATH_NAME} --daemon --rpc --rpc_control --network=3 --data_path=${DATA_PATH}7 --rpc_addr=0.0.0.0 --rpc_port=${RPC_PORT}71 --port=${P2P_PORT}12 --witness --witness_account=/root/ccn/config-file/config-file-new/0x918d3fe1dbff02fc7521d4a04b50017ce1a7c2ea.json --password=12345678 >> /dev/null 2>&1 &
    nohup ${APPLICATION_PATH_NAME} --daemon --rpc --rpc_control --network=3 --data_path=${DATA_PATH}8 --rpc_addr=0.0.0.0 --rpc_port=${RPC_PORT}72 --port=${P2P_PORT}13 --witness --witness_account=/root/ccn/config-file/config-file-new/0x929f336edb0a39ad5532a462d4a84e1546c5e5de.json --password=12345678 >> /dev/null 2>&1 &
    nohup ${APPLICATION_PATH_NAME} --daemon --rpc --rpc_control --network=3 --data_path=${DATA_PATH}9 --rpc_addr=0.0.0.0 --rpc_port=${RPC_PORT}73 --port=${P2P_PORT}14 --witness --witness_account=/root/ccn/config-file/config-file-new/0xa11b98c54d4189adda8eda97e13c214fedaf0a0f.json --password=12345678 >> /dev/null 2>&1 &
    nohup ${APPLICATION_PATH_NAME} --daemon --rpc --rpc_control --network=3 --data_path=${DATA_PATH}10 --rpc_addr=0.0.0.0 --rpc_port=${RPC_PORT}74 --port=${P2P_PORT}15 --witness --witness_account=/root/ccn/config-file/config-file-new/0xa65ec5c65031d668094cb1b81bb8253ea64a23d7.json --password=12345678 >> /dev/null 2>&1 &
}

function startPart2(){
    nohup ${APPLICATION_PATH_NAME} --daemon --rpc --rpc_control --network=3 --data_path=${DATA_PATH}11 --rpc_addr=0.0.0.0 --rpc_port=${RPC_PORT}75 --port=${P2P_PORT}16 --witness --witness_account=/root/ccn/config-file/config-file-new/0xba618c1e3e90d16e6c15d92ed198780dc4ad39c2.json --password=12345678 >> /dev/null 2>&1 &
    nohup ${APPLICATION_PATH_NAME} --daemon --rpc --rpc_control --network=3 --data_path=${DATA_PATH}12 --rpc_addr=0.0.0.0 --rpc_port=${RPC_PORT}76 --port=${P2P_PORT}17 --witness --witness_account=/root/ccn/config-file/config-file-new/0xc2cf7b9eb048c34c2b00175a884543366bbcd029.json --password=12345678 >> /dev/null 2>&1 &
    nohup ${APPLICATION_PATH_NAME} --daemon --rpc --rpc_control --network=3 --data_path=${DATA_PATH}13 --rpc_addr=0.0.0.0 --rpc_port=${RPC_PORT}77 --port=${P2P_PORT}18 --witness --witness_account=/root/ccn/config-file/config-file-new/0xc543a3868f3613eecd109761f71e31832ecf51ba.json --password=12345678 >> /dev/null 2>&1 &
    nohup ${APPLICATION_PATH_NAME} --daemon --rpc --rpc_control --network=3 --data_path=${DATA_PATH}14 --rpc_addr=0.0.0.0 --rpc_port=${RPC_PORT}78 --port=${P2P_PORT}19 --witness --witness_account=/root/ccn/config-file/config-file-new/0xdab8a5fb82eb24ad321751bb2dd8e4cc9a4e45e5.json --password=12345678 >> /dev/null 2>&1 &
    nohup ${APPLICATION_PATH_NAME} --daemon --rpc --rpc_control --network=3 --data_path=${DATA_PATH}15 --rpc_addr=0.0.0.0 --rpc_port=${RPC_PORT}79 --port=${P2P_PORT}20 --witness --witness_account=/root/ccn/config-file/config-file-new/0x1144B522F45265C2DFDBAEE8E324719E63A1694C.json --password=12345678 >> /dev/null 2>&1 &
    nohup ${APPLICATION_PATH_NAME} --daemon --rpc --rpc_control --network=3 --data_path=${DATA_PATH}16 --rpc_addr=0.0.0.0 --rpc_port=${RPC_PORT}80 --port=${P2P_PORT}21 --witness --witness_account=/root/ccn/config-file/config-file-new/part2/0x088415bbf9b7dfe93f2231fa5dd527a04c874845.json --password=12345678 >> /dev/null 2>&1 &
    nohup ${APPLICATION_PATH_NAME} --daemon --rpc --rpc_control --network=3 --data_path=${DATA_PATH}17 --rpc_addr=0.0.0.0 --rpc_port=${RPC_PORT}81 --port=${P2P_PORT}22 --witness --witness_account=/root/ccn/config-file/config-file-new/part2/0x4158f69f4499f9c5b7d5744ca2020741fd9fc0bc.json --password=12345678 >> /dev/null 2>&1 &
    nohup ${APPLICATION_PATH_NAME} --daemon --rpc --rpc_control --network=3 --data_path=${DATA_PATH}18 --rpc_addr=0.0.0.0 --rpc_port=${RPC_PORT}82 --port=${P2P_PORT}23 --witness --witness_account=/root/ccn/config-file/config-file-new/part2/0x820a7d4e3d816eabb6e2a5bfe6e5eac60c39c406.json --password=12345678 >> /dev/null 2>&1 &
    nohup ${APPLICATION_PATH_NAME} --daemon --rpc --rpc_control --network=3 --data_path=${DATA_PATH}19 --rpc_addr=0.0.0.0 --rpc_port=${RPC_PORT}83 --port=${P2P_PORT}24 --witness --witness_account=/root/ccn/config-file/config-file-new/part2/0x8b5c7ce9fbaed1bebb3043416684bc6913962670.json --password=12345678 >> /dev/null 2>&1 &
    nohup ${APPLICATION_PATH_NAME} --daemon --rpc --rpc_control --network=3 --data_path=${DATA_PATH}20 --rpc_addr=0.0.0.0 --rpc_port=${RPC_PORT}84 --port=${P2P_PORT}25 --witness --witness_account=/root/ccn/config-file/config-file-new/part2/0xb5575c29ba308cac3ff476485e87e4b4ef604f9b.json --password=12345678 >> /dev/null 2>&1 &
}

function startPart3(){
    nohup ${APPLICATION_PATH_NAME} --daemon --rpc --rpc_control --network=3 --data_path=${DATA_PATH}21 --rpc_addr=0.0.0.0 --rpc_port=${RPC_PORT}85 --port=${P2P_PORT}26 --witness --witness_account=/root/ccn/config-file/config-file-new/part3/0x0c19b28490879dc76a6c1584017371f0ff2534bb.json --password=12345678 >> /dev/null 2>&1 &
    nohup ${APPLICATION_PATH_NAME} --daemon --rpc --rpc_control --network=3 --data_path=${DATA_PATH}22 --rpc_addr=0.0.0.0 --rpc_port=${RPC_PORT}86 --port=${P2P_PORT}27 --witness --witness_account=/root/ccn/config-file/config-file-new/part3/0x4cbe2bec9bc8c0edf3d681fb74681ebcf6d1f5eb.json --password=12345678 >> /dev/null 2>&1 &
    nohup ${APPLICATION_PATH_NAME} --daemon --rpc --rpc_control --network=3 --data_path=${DATA_PATH}23 --rpc_addr=0.0.0.0 --rpc_port=${RPC_PORT}87 --port=${P2P_PORT}28 --witness --witness_account=/root/ccn/config-file/config-file-new/part3/0x6b15660ae66f6864be4ab5de49abb22cba3f6270.json --password=12345678 >> /dev/null 2>&1 &
    nohup ${APPLICATION_PATH_NAME} --daemon --rpc --rpc_control --network=3 --data_path=${DATA_PATH}24 --rpc_addr=0.0.0.0 --rpc_port=${RPC_PORT}88 --port=${P2P_PORT}29 --witness --witness_account=/root/ccn/config-file/config-file-new/part3/0x70659723d63f7ce6586e3dcb012e0ea21b77f1b4.json --password=12345678 >> /dev/null 2>&1 &
    nohup ${APPLICATION_PATH_NAME} --daemon --rpc --rpc_control --network=3 --data_path=${DATA_PATH}25 --rpc_addr=0.0.0.0 --rpc_port=${RPC_PORT}89 --port=${P2P_PORT}30 --witness --witness_account=/root/ccn/config-file/config-file-new/part3/0x7f24f7a7caf8c6ec269debff91a133defd305342.json --password=12345678 >> /dev/null 2>&1 &
    nohup ${APPLICATION_PATH_NAME} --daemon --rpc --rpc_control --network=3 --data_path=${DATA_PATH}26 --rpc_addr=0.0.0.0 --rpc_port=${RPC_PORT}90 --port=${P2P_PORT}31 --witness --witness_account=/root/ccn/config-file/config-file-new/part3/0x863f64007c3591695b7abf8ff5fad1d0dcda2b81.json --password=12345678 >> /dev/null 2>&1 &
    nohup ${APPLICATION_PATH_NAME} --daemon --rpc --rpc_control --network=3 --data_path=${DATA_PATH}27 --rpc_addr=0.0.0.0 --rpc_port=${RPC_PORT}91 --port=${P2P_PORT}32 --witness --witness_account=/root/ccn/config-file/config-file-new/part3/0xa4048b64056ed70efd6ea72c62819ea3d88c2b24.json --password=12345678 >> /dev/null 2>&1 &
    nohup ${APPLICATION_PATH_NAME} --daemon --rpc --rpc_control --network=3 --data_path=${DATA_PATH}28 --rpc_addr=0.0.0.0 --rpc_port=${RPC_PORT}92 --port=${P2P_PORT}33 --witness --witness_account=/root/ccn/config-file/config-file-new/part3/0xadbe5bcf5a09bce4091d130e9b08d59726a6f7cd.json --password=12345678 >> /dev/null 2>&1 &
}

if [ "$#" -le "1" ]; then
{
    echo "run all"
    startPart1
    startPart2
    startPart3
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