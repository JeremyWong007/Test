#！/bin/bash

source globalInfo.sh
pkillAndWait mcp

cd /root/ccn/localnet/mcp-mini
rm -rf backup chaindb keydb log p2pdb

echo "clear mcp ok"
