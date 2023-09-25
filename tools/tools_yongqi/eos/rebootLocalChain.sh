#!/bin/bash
set -u
set -x

# COMMAND_PATH=$0
# TOOLS_PATH=${COMMAND_PATH%/*}
# TOOLS_PATH=$(pwd)${TOOLS_PATH#*.}
# echo "TOOLS_PATH is "${TOOLS_PATH}

# cd ${TOOLS_PATH}
# pkill nodeos
# sleep 0.1

./unlock.sh
./ctrl_local.sh clean.sh 
sleep 2
./ctrl_local.sh genesis_start.sh
sleep 1
./setConfigNormal.sh
./setConfigVote3.sh