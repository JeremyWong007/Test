#！/bin/bash

source globalInfo.sh
pkillAndWait mcp

cd /root/ccn/localnet/backmcp-mini
rm -rf backup chaindb keydb log p2pdb

echo "clear mcp ok"
