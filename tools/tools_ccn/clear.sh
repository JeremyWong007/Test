#！/bin/bash

source globalInfo.sh
echo $1
cd $1
rm -rf backup chaindb keydb log p2pdb
echo "clear mcp ok"
