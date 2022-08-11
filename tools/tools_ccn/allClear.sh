#！/bin/bash

source globalInfo.sh
pkillAndWait mcp

cd /root/ccn/localnet/
for dir in `ls`; do
    cd $dir
    for dir2 in `ls`; do
        cd $dir2
        rm -rf backup chaindb keydb log p2pdb
        cd ..
    done
    cd ..
done

echo "clear mcp ok"
