#! /bin/bash
set -x

cleos --url system newaccount eosio --transfer accountnum11 EOS8mUftJXepGzdQ2TaCduNuSPAfXJHf22uex4u41ab1EVv9EAhWt --stake-net "100000000.0000 EOS" --stake-cpu "100000000.0000 EOS" --buy-ram-kbytes 8
cleos --url system newaccount eosio --transfer accountnum12 EOS8mUftJXepGzdQ2TaCduNuSPAfXJHf22uex4u41ab1EVv9EAhWt --stake-net "100000000.0000 EOS" --stake-cpu "100000000.0000 EOS" --buy-ram-kbytes 8
cleos --url system newaccount eosio --transfer accountnum13 EOS8mUftJXepGzdQ2TaCduNuSPAfXJHf22uex4u41ab1EVv9EAhWt --stake-net "100000000.0000 EOS" --stake-cpu "100000000.0000 EOS" --buy-ram-kbytes 8

cleos --url system regproducer accountnum11 EOS5EfU2fDgHZTNwPhuoHJgKcrNJ3PbyaYMHMrgMnBpVffWjgeJjX https://accountnum11.com
cleos --url system regproducer accountnum12 EOS5EfU2fDgHZTNwPhuoHJgKcrNJ3PbyaYMHMrgMnBpVffWjgeJjX https://accountnum12.com
cleos --url system regproducer accountnum13 EOS5EfU2fDgHZTNwPhuoHJgKcrNJ3PbyaYMHMrgMnBpVffWjgeJjX https://accountnum13.com

cleos --url system listproducers

cleos --url system voteproducer prods accountnum11 accountnum11 accountnum12 accountnum13

cleos --url transfer eosio accountnum11 "9.0000 EOS"
cleos --url get info
