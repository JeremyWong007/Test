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
}

function usage() {
    echo "Usage:"
    echo " getopt <optstring> <parameters>"
    echo ""
    echo "Exapmple:"
    echo " ./ctrlServers.sh --copymcp"
    echo " ./ctrlServers.sh --copytest1"
    exit 1
}

function copymcp() {
    scp -P 1322 -r /root/ccn/git/mcp/build/mcp root@18.163.123.3:/root/ccn/git/mcp/build/
}

function copytest1() {
    cp -rf /root/ccn/git/mcp/build/mcp /root/ccn/file/test1
    scp -P 1322 -r /root/ccn/file/test1 root@18.163.123.3:/root/ccn/file/test1
}

ARGS=`getopt -o h --long copymcp,copytest1 -n 'ctrlServers.sh' -- "$@"`
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


