#！/bin/bash

function copyFileToTestServers(){
    scp -P 22 -r -i /root/ccn/certificate/jp-dev-test-public.pem /root/ccn/git/mcp/build/mcp ubuntu@18.182.45.18:/usr/local/jeremy/
}
function copyFileToVRFTestServer(){
    ssh  root@18.163.123.3 -p 1322  -i ./xxxxxx
    scp -P 1322 -r /root/ccn/git/boost_1_66_0.tar.bz2 root@18.163.123.3:/root/jeremy
    scp -P 1322 -r /root/ccn/git/mcp/build/mcp root@18.163.123.3:/root/ccn/git/mcp/build/
    scp -P 1322 -r /root/ccn/git/mcp/build/mcp.tgz root@18.163.123.3:/root/ccn/git/mcp/build/
    scp -P 1322 -r /root/ccn/config-file root@18.163.123.3:/root/ccn/
    scp -P 1322 -r /root/ccn/localnet/mini4/1/nodekey root@18.163.123.3:/root/ccn/localnet/mini4/1/
    scp -P 1322 -r /root/ccn/localnet/testmode/* root@18.163.123.3:/root/ccn/localnet/testmode/
}


