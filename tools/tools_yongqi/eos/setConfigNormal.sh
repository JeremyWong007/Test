#! /bin/bash
set -u
set -e
set -x

#unlock wallet first.
#input keys to wallet

# CONTRACT_PATH=$1
# echo CONTRACT_PATH is ${CONTRACT_PATH}

#CONTRACT_PATH=/home/d/projects/eosio.contracts/build/contracts
CONTRACT_PATH=/root/projects/threed/bpc-atlantis-contracts/build/contracts
#CONTRACT_BOOT_PATH=/home/d/projects/eos/contracts/contracts
CONTRACT_BOOT_PATH=/root/projects/threed/contracts

# EOS6Kc7LVUHVxauut2rj8Rwk21mXAYpvLoNsJf3C1vFLFjhGeeHHM=KEY:5JLrjLzKiWvecrUkBBPEBm4Wt8F7ECygLNnLhhLW64fCGP5RUvH
cleos create account eosio eosio.bpay EOS6Kc7LVUHVxauut2rj8Rwk21mXAYpvLoNsJf3C1vFLFjhGeeHHM
cleos create account eosio eosio.msig EOS6Kc7LVUHVxauut2rj8Rwk21mXAYpvLoNsJf3C1vFLFjhGeeHHM
cleos create account eosio eosio.names EOS6Kc7LVUHVxauut2rj8Rwk21mXAYpvLoNsJf3C1vFLFjhGeeHHM
cleos create account eosio eosio.ram EOS6Kc7LVUHVxauut2rj8Rwk21mXAYpvLoNsJf3C1vFLFjhGeeHHM
cleos create account eosio eosio.ramfee EOS6Kc7LVUHVxauut2rj8Rwk21mXAYpvLoNsJf3C1vFLFjhGeeHHM
cleos create account eosio eosio.saving EOS6Kc7LVUHVxauut2rj8Rwk21mXAYpvLoNsJf3C1vFLFjhGeeHHM
cleos create account eosio eosio.stake EOS6Kc7LVUHVxauut2rj8Rwk21mXAYpvLoNsJf3C1vFLFjhGeeHHM
cleos create account eosio eosio.token EOS6Kc7LVUHVxauut2rj8Rwk21mXAYpvLoNsJf3C1vFLFjhGeeHHM
cleos create account eosio eosio.vpay EOS6Kc7LVUHVxauut2rj8Rwk21mXAYpvLoNsJf3C1vFLFjhGeeHHM
cleos create account eosio eosio.rex EOS6Kc7LVUHVxauut2rj8Rwk21mXAYpvLoNsJf3C1vFLFjhGeeHHM

curl --request POST --url http://127.0.0.1:8888/v1/producer/schedule_protocol_feature_activations   -d '{"protocol_features_to_activate": ["0ec7e080177b2c02b278d5088611686b49d739925a92d9bfcacd7fc6b74053bd"]}'
echo "sleep 1 start"
sleep 1
echo "sleep 1 end"

echo "CONTRACT_BOOT_PATH is "$CONTRACT_BOOT_PATH
cd $CONTRACT_BOOT_PATH
cleos set contract eosio ./eosio.boot
cleos push transaction '{"delay_sec":0,"max_cpu_usage_ms":0,"actions":[{"account":"eosio","name":"activate","data":{"feature_digest":"299dcb6af692324b899b39f16d5a530a33062804e41f09dc97e9f156b4476707"},"authorization":[{"actor":"eosio","permission":"active"}]}]}'

echo "CONTRACT_PATH is "$CONTRACT_PATH
cd $CONTRACT_PATH

sleep 1
cleos set contract eosio ./eosio.bios
cleos set contract eosio.token ./eosio.token/
cleos set contract eosio.msig ./eosio.msig/

cleos push action eosio.token create '[ "eosio", "3000000000.0000 SYS" ]' -p eosio.token@active
cleos push action eosio.token issue '[ "eosio", "1000000000.0000 SYS", "memo" ]' -p eosio@active
echo "sleep 1 start"
sleep 1
echo "sleep 1 end"
cleos set contract eosio ./eosio.system
cleos push action eosio setpriv '["eosio.msig", 1]' -p eosio@active
cleos push action eosio init '["0", "4,SYS"]' -p eosio@active
echo "log1"
