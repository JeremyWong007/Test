#! /bin/bash
set -x

echo "############################################################################"
echo "test command start:"

curl --request POST --url http://127.0.0.1:8888/eos/taf_getInfo
curl --request POST --url http://127.0.0.1:8888/eos/taf_getMiners
curl --request POST --url http://127.0.0.1:8888/eos/taf_getMinerSchedule

#计算投票率：
cleos query form T1HHsxQ3igveVAfbXipkWH89J6VFS5QGF6T T1HHsxQ3igveVAfbXipkWH89J6VFS5QGF6T global
cleos query cryptocurrency stats T1phSrWeGNQQvypVEn7kKM1MJbN6Tbof EOS
#投票率=total_activated_stake /10000 / supply

#测试rocksdb
#公钥：EOS7u97SYkF1hqQtJADSm3sz6VYReXfSWkLRBBdGEbH6X22TkebGE
#私钥：5K7aoyyXtJJSuS2devN2PedLe5Tinccx2KaK5eonff58onvazm5
#account address: T1Jab9vtJ3uH2eeCDeti1jLpwW3AfkYMuGN
function test_rocksdb(){
    cleos wallet importkey --private-key 5K7aoyyXtJJSuS2devN2PedLe5Tinccx2KaK5eonff58onvazm5
    cleos new account EOS7u97SYkF1hqQtJADSm3sz6VYReXfSWkLRBBdGEbH6X22TkebGE
    cleos query account T1Jab9vtJ3uH2eeCDeti1jLpwW3AfkYMuGN

    cleos transfer T1FwoGPJdMdCaBxiXXJYuQHQs1MnRzT9vTA T1Jab9vtJ3uH2eeCDeti1jLpwW3AfkYMuGN "2000.0000 EOS"
    cleos producer delegatesource T1Jab9vtJ3uH2eeCDeti1jLpwW3AfkYMuGN T1Jab9vtJ3uH2eeCDeti1jLpwW3AfkYMuGN "1000.0000 EOS" "1000.0000 EOS"
    #cleos update contract T1Jab9vtJ3uH2eeCDeti1jLpwW3AfkYMuGN /data/info/git/eos/kv-test/contracts/kv_map --max-net-usage 30000 -p T1Jab9vtJ3uH2eeCDeti1jLpwW3AfkYMuGN@active
    #cleos update contract T1Jab9vtJ3uH2eeCDeti1jLpwW3AfkYMuGN /data/info/git/eos/build/unittests/test-contracts/kv_bios --max-net-usage 30000 -p T1Jab9vtJ3uH2eeCDeti1jLpwW3AfkYMuGN@active
    cleos update contract T1Jab9vtJ3uH2eeCDeti1jLpwW3AfkYMuGN /data/info/git/eos-ide-2.1/examples/kv_map/build/kv_map --max-net-usage 30000 -p T1Jab9vtJ3uH2eeCDeti1jLpwW3AfkYMuGN@active
    cleos send action T1Jab9vtJ3uH2eeCDeti1jLpwW3AfkYMuGN upsert '[3, "jane.acct1334455" "jane", "doe", "1 main st", "new york", "NY", "USA", "123"]' -p T1Jab9vtJ3uH2eeCDeti1jLpwW3AfkYMuGN@active
    cleos send action T1Jab9vtJ3uH2eeCDeti1jLpwW3AfkYMuGN get '[3]' -p T1Jab9vtJ3uH2eeCDeti1jLpwW3AfkYMuGN@active
}
function test_contract(){
    cleos wallet importkey --private-key 5KaQvZHjAdVDw9Vj9g75gdZA9moTf63jLp7j1sdk2swfCbRMN9f
    cleos new account EOS62RicgwQmFVqfCdNWvJirgdDRvp3SjS3dqVMU7i4pPypPUtQyK
    cleos query account T15LDsm6pUfsCU8dszCn9nxiHHiYULV1WK9

    cleos transfer T1FwoGPJdMdCaBxiXXJYuQHQs1MnRzT9vTA T15LDsm6pUfsCU8dszCn9nxiHHiYULV1WK9 "2000.0000 EOS"
    cleos producer delegatesource T15LDsm6pUfsCU8dszCn9nxiHHiYULV1WK9 T15LDsm6pUfsCU8dszCn9nxiHHiYULV1WK9 "1000.0000 EOS" "1000.0000 EOS"
    cleos update contract T15LDsm6pUfsCU8dszCn9nxiHHiYULV1WK9 /data/info/git/eos/build/unittests/test-contracts/asserter --max-net-usage 30000 -p T15LDsm6pUfsCU8dszCn9nxiHHiYULV1WK9@active
    
    cleos send action T15LDsm6pUfsCU8dszCn9nxiHHiYULV1WK9 procassert '[1, "Hello assert"]' -p T15LDsm6pUfsCU8dszCn9nxiHHiYULV1WK9@active
    cleos send action T15LDsm6pUfsCU8dszCn9nxiHHiYULV1WK9 provereset '[]' -p T15LDsm6pUfsCU8dszCn9nxiHHiYULV1WK9@active
}
test_rocksdb
test_contract
