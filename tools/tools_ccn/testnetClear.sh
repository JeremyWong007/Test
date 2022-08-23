#！/bin/bash

source globalInfo.sh
getApplicationName $*

pkillAndWait $APPLICATION_NAME

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

cd ${DATA_PATH}
for dir in `ls`; do
    cd $dir
    rm -rf backup chaindb keydb log p2pdb
    cd ..
done

echo "clear ${DATA_PATH} ok"
