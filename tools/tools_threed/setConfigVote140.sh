#! /bin/bash
set -u
set -x

WORK_NODES=$1

#基金会帐户 account address: T17Y2vaQtyQmGVm3MZrvS3hGFj5zVXvo48S
cleos wallet importkey --private-key 5KENnPegq7hiPBZYRuuD8x4QonnqErFWz4gMiSGCNEcRvvb4KJE
cleos new account EOS8VS2tKPTznw8BntttKxGzCR6rupgQYeh8LmKj7dXNAsMZYj8NJ
cleos transfer T1HHsxQ3igveVAfbXipkWH89J6VFS5QGF6T T17Y2vaQtyQmGVm3MZrvS3hGFj5zVXvo48S "240000000.0000 EOS"
AccountFoundation="T17Y2vaQtyQmGVm3MZrvS3hGFj5zVXvo48S"

#团队帐户 account address: T1BvMyqRo9BnHKi1DamjF1MwWcGT3EGfrCA  【做为水龙头帐户】
cleos wallet importkey --private-key 5JGdHMeVJc2SpvnY8UPLu4TyxUE3AXQFoxM2pC44hVzvyHKiBYZ
cleos new account EOS8Gv9KB3M5QmNu69j7BsGXyYQGFAiQWxK9RRmGrCTLuSUQzRE3o
cleos transfer T1HHsxQ3igveVAfbXipkWH89J6VFS5QGF6T T1BvMyqRo9BnHKi1DamjF1MwWcGT3EGfrCA "180000000.0000 EOS"

#投资者帐户 account address: T1FwoGPJdMdCaBxiXXJYuQHQs1MnRzT9vTA
cleos wallet importkey --private-key 5KLuHULoc5W29ULdtaDUmgG9k29QngNdwKmrqFbQWV2SsKPxtV2
cleos new account EOS5h8yr8Fuz5XLVcVZL3kYQYaR8bqBJhXK4vFRVG3ThiKDt67Rsw
cleos transfer T1HHsxQ3igveVAfbXipkWH89J6VFS5QGF6T T1FwoGPJdMdCaBxiXXJYuQHQs1MnRzT9vTA "780000000.0000 EOS"
AccountInvestor="T1FwoGPJdMdCaBxiXXJYuQHQs1MnRzT9vTA"

#给tafbas抵压cpu和net，保证创建帐户命令得到正确执行
cleos producer delegatesource T1FwoGPJdMdCaBxiXXJYuQHQs1MnRzT9vTA T17pFoCekTq9Ukui6jgFhu2QLc9F5tMvJif "500 EOS" "500 EOS"

source globalInfo.sh

# create all account and get name
ProducerNameArray=()
echo "create all account and get name:"
#注意，i=0时未使用，对应于创世节点（创世节点的帐户名为系统帐户）
for((i=1;i<$WORK_NODES;i++));
do
    PUB_KEY=${public_keys[i]}
    RSP=`cleos new account $PUB_KEY`
    RESULT=`echo $RSP | awk -F 'account address: ' '{print $2}' `
    # if is empty, exit
    ProducerNameArray[i]=$RESULT
    echo $i $RESULT
done

# transfer to work node
for((i=1;i<$WORK_NODES;i++));
do
    NAME=${ProducerNameArray[i]}
    ASSET=`echo "1+0.0001*$i" | bc`
    cleos producer delegatesource $AccountFoundation $NAME "1 EOS" "1 EOS"
    cleos transfer $AccountFoundation $NAME "$ASSET EOS"
    #ASSET_HALF=`echo "$ASSET-0.5" | bc`
    cleos producer delegatesource $NAME $NAME "$ASSET EOS" "0.0000 EOS"
    cleos producer regproducer $NAME EOS5EfU2fDgHZTNwPhuoHJgKcrNJ3PbyaYMHMrgMnBpVffWjgeJjX https://$NAME.com
    cleos producer voteproducers prods $NAME $NAME
done

cleos producer delegatesource $AccountInvestor $AccountInvestor "120000000.0000 EOS" "120000000.0000 EOS"
#ProducerNameArray[1]帐户：
cleos producer voteproducers prods  $AccountInvestor ${ProducerNameArray[1]}

cleos producer listproducers