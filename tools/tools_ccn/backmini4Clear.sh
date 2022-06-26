#！/bin/bash

source globalInfo.sh
pkillAndWait mcp

cd /root/ccn/localnet/backmini4/
for dir in `ls`; do
    cd $dir
    rm -rf backup chaindb keydb log p2pdb
    cd ..
done

echo "clear mcp ok"
