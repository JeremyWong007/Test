#! /bin/bash
set -x

#基金会帐户 account address: T17Y2vaQtyQmGVm3MZrvS3hGFj5zVXvo48S
cleos wallet importkey --private-key 5KENnPegq7hiPBZYRuuD8x4QonnqErFWz4gMiSGCNEcRvvb4KJE
cleos new account EOS8VS2tKPTznw8BntttKxGzCR6rupgQYeh8LmKj7dXNAsMZYj8NJ
cleos transfer eosio T17Y2vaQtyQmGVm3MZrvS3hGFj5zVXvo48S "240000000.0000 EOS"

#团队帐户 account address: T1BvMyqRo9BnHKi1DamjF1MwWcGT3EGfrCA
cleos wallet importkey --private-key 5JGdHMeVJc2SpvnY8UPLu4TyxUE3AXQFoxM2pC44hVzvyHKiBYZ
cleos new account EOS8Gv9KB3M5QmNu69j7BsGXyYQGFAiQWxK9RRmGrCTLuSUQzRE3o
cleos transfer eosio T1BvMyqRo9BnHKi1DamjF1MwWcGT3EGfrCA "180000000.0000 EOS"

#种子轮帐户 account address: T1FwoGPJdMdCaBxiXXJYuQHQs1MnRzT9vTA
cleos wallet importkey --private-key 5KLuHULoc5W29ULdtaDUmgG9k29QngNdwKmrqFbQWV2SsKPxtV2
cleos new account EOS5h8yr8Fuz5XLVcVZL3kYQYaR8bqBJhXK4vFRVG3ThiKDt67Rsw
cleos transfer eosio T1FwoGPJdMdCaBxiXXJYuQHQs1MnRzT9vTA "60000000.0000 EOS"

#天使轮帐户 account address: T18ZX5kBKHQWjnRfmAg1a69MwYnipZwYEPv
cleos wallet importkey --private-key 5KJBtxaU5KA3o5u59i2SRANGvh2otv8N6H4zRBWA4mpFLSkJzN3
cleos new account EOS5icRxEVxJEA6o4GbV5fN9XwkZjMVWaavBNZu7ZX7D2tVWerPmc
cleos transfer eosio T18ZX5kBKHQWjnRfmAg1a69MwYnipZwYEPv "84000000.0000 EOS"

#私募帐户 account address: T1MHkPp5EJ2MhsztVps7MkNaEGa84rWojQp
cleos wallet importkey --private-key 5K8JvGrUkVDTukZJJmAXYxgjowNrjrxprMNumw1SEvVyjM5xP8W
cleos new account EOS66VmFxoe3oKMc1yT8CmVaoKXkLTvfnRJVyVuW9L7xwrrYV5XZp
cleos transfer eosio T1MHkPp5EJ2MhsztVps7MkNaEGa84rWojQp "360000000.0000 EOS"

#ICO帐户 account address: T18otnQRXsMjdrMgLWp7XdbXKL8jgJvB3uQ
cleos wallet importkey --private-key 5Jk71xYbN7spuCyxu34mdMaAiUtEwCjztaqWziK9o4WAHbTNScM
cleos new account EOS5dAwSsoGDEhG5Gvy58bRoFqKxC5Yj3q33G8HPUY9CUap2U2zrg
cleos transfer eosio T18otnQRXsMjdrMgLWp7XdbXKL8jgJvB3uQ "276000000.0000 EOS"

cleos tachyon newaccount eosio --transfer MAKER_LONGNAME_11 EOS8mUftJXepGzdQ2TaCduNuSPAfXJHf22uex4u41ab1EVv9EAhWt --stake-net "100000000.0000 EOS" --stake-cpu "100000000.0000 EOS"
cleos tachyon newaccount eosio --transfer MAKER_LONGNAME_12 EOS8mUftJXepGzdQ2TaCduNuSPAfXJHf22uex4u41ab1EVv9EAhWt --stake-net "100000000.0000 EOS" --stake-cpu "100000000.0000 EOS"
cleos tachyon newaccount eosio --transfer MAKER_LONGNAME_13 EOS8mUftJXepGzdQ2TaCduNuSPAfXJHf22uex4u41ab1EVv9EAhWt --stake-net "100000000.0000 EOS" --stake-cpu "100000000.0000 EOS"

cleos producer regproducer MAKER_LONGNAME_11 EOS5EfU2fDgHZTNwPhuoHJgKcrNJ3PbyaYMHMrgMnBpVffWjgeJjX https://accountnum11.com
cleos producer regproducer MAKER_LONGNAME_12 EOS5EfU2fDgHZTNwPhuoHJgKcrNJ3PbyaYMHMrgMnBpVffWjgeJjX https://accountnum12.com
cleos producer regproducer MAKER_LONGNAME_13 EOS5EfU2fDgHZTNwPhuoHJgKcrNJ3PbyaYMHMrgMnBpVffWjgeJjX https://accountnum13.com

cleos producer listproducers

cleos producer voteproducers prods  MAKER_LONGNAME_11 MAKER_LONGNAME_11 MAKER_LONGNAME_12 MAKER_LONGNAME_13

cleos transfer eosio MAKER_LONGNAME_11 "9.0000 EOS"
