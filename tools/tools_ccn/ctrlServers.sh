#！/bin/bash

function copyFileToTestServers(){
    scp -P 22 -r -i /root/ccn/certificate/jp-dev-test-public.pem /root/ccn/git/mcp/build/mcp ubuntu@18.182.45.18:/usr/local/jeremy/
}

