#！/bin/bash

function copyFileToTestServers(){
    scp -P 22 -r -i /root/ccn/certificate/jp-dev-test-public.pem /root/ccn/git/mcp/build/mcp ubuntu@18.182.45.18:/usr/local/jeremy/
}
function copyFileToVRFTestServer(){
    ssh  root@18.163.123.3 -p 1322  -i ./xxxxxx
    scp -P 1322 -r /root/ccn/git/boost_1_66_0.tar.bz2 root@18.163.123.3:/root/jeremy
    scp -P 1322 -r /root/ccn/git/mcp/build/mcp root@18.163.123.3:/root/ccn/git/mcp/build/
    scp -P 1322 -r /root/ccn/git/mcp/build/mcp.tgz root@18.163.123.3:/root/ccn/git/mcp/build/
    scp -P 1322 -r /root/ccn/config-file/config-file-new root@18.163.123.3:/root/ccn/config-file/
    scp -P 1322 -r /root/ccn/localnet/mini4/1/nodekey root@18.163.123.3:/root/ccn/localnet/mini4/1/
    scp -P 1322 -r /root/ccn/localnet/testmode/* root@18.163.123.3:/root/ccn/localnet/testmode/
    scp -P 1322 -r root@18.163.123.3:/root/ccn/localnet/testmode/2/nodekey /root/ccn/localnet/testmode/2/
    sshpass -p 'jkdsair345f_mcpR' scp -o StrictHostKeyChecking=no -o ConnectTimeout=10 -P 22 -r root@13.212.113.18:/usr/local/ccn-mcp/mcp-programnode/chaindb.tar.gz /tmp
    scp -P 22 -r root@13.212.113.18:/usr/local/ccn-mcp/mcp-programnode/chaindb.tar.gz /tmp
    nohup /root/ccn/git/mcp/build/mcp --daemon --rpc --rpc_control --network=2 --data_path=/root/ccn/test/huygens --rpc_addr=0.0.0.0 --rpc_port=8765 >> /dev/null 2>&1 &
}

function usage() {
    echo "Usage:"
    echo " getopt <optstring> <parameters>"
    echo ""
    echo "Exapmple:"
    echo " ./ctrlServers.sh --copymcp"
    echo " ./ctrlServers.sh --copytest1"
    echo " ./ctrlServers.sh --copy2server"
    exit 1
}

function copymcp() {
    scp -P 1322 -r /root/ccn/git/mcp/build/mcp root@18.163.123.3:/root/ccn/git/mcp/build/
}

function copytest1() {
    cp -rf /root/ccn/git/mcp/build/mcp /root/ccn/file/test1
    scp -P 1322 -r /root/ccn/file/test1 root@18.163.123.3:/root/ccn/file/test1
}

function copy2server() {
    echo "from:$3"
    echo "to:$4"
    scp -P 1322 -r $3 root@18.163.123.3:$4
}

function copy2local() {
    echo "from:$3"
    echo "to:$4"
    scp -P 1322 -r root@18.163.123.3:$4 $3
}

ARGS=`getopt -o h --long copymcp,copytest1,copy2server,copy2local -n 'ctrlServers.sh' -- "$@"`
if [ $? != 0 ]; then
    echo "Terminating..."
    exit 1
fi

#将规范化后的命令行参数分配至位置参数（$1,$2,...)
eval set -- "${ARGS}"
while true
do
    case "$1" in
        --copymcp)
            echo "copy mcp in"
            copymcp
            shift
            ;;
        --copytest1)
            echo "copy test1 in"
            copytest1
            shift
            ;;
        --copy2server)
            echo "copy to server in"
            copy2server $@
            shift
            ;;
        --copy2local)
            echo "copy to local in"
            copy2local $@
            shift
            ;;
        --)
            shift
            break
            ;;
        -h)
            usage
            ;;
        *)
            echo "Internal error!"
            exit 1
            ;;
    esac
done


