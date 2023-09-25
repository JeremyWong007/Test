#! /bin/bash
set -x

#PUBKEY:EOS8BcU7CKpNggBGPKQVCyHsSuh9eLRPAd19ewrZ3dMfkRCx5iwbi  <-> PRIVATEKEY:5KBtJCov6sQdQJyUMuL4MfNxGDEM171Dj1eWz72Ngt4wj7nZdk8
cleos system newaccount eosio --transfer accountnum11 EOS8BcU7CKpNggBGPKQVCyHsSuh9eLRPAd19ewrZ3dMfkRCx5iwbi --stake-net "100000000.0000 SYS" --stake-cpu "100000000.0000 SYS" --buy-ram-kbytes 8
cleos system newaccount eosio --transfer accountnum12 EOS8BcU7CKpNggBGPKQVCyHsSuh9eLRPAd19ewrZ3dMfkRCx5iwbi --stake-net "100000000.0000 SYS" --stake-cpu "100000000.0000 SYS" --buy-ram-kbytes 8
cleos system newaccount eosio --transfer accountnum13 EOS8BcU7CKpNggBGPKQVCyHsSuh9eLRPAd19ewrZ3dMfkRCx5iwbi --stake-net "100000000.0000 SYS" --stake-cpu "100000000.0000 SYS" --buy-ram-kbytes 8

#PUBKEY:EOS5EfU2fDgHZTNwPhuoHJgKcrNJ3PbyaYMHMrgMnBpVffWjgeJjX  <-> PRIVATEKEY:5HxK6mfoNr1pbnbYs1AmsKjavJQaoxiNVUdeJD6ZPFZkQvGcZVM
cleos system regproducer accountnum11 EOS5EfU2fDgHZTNwPhuoHJgKcrNJ3PbyaYMHMrgMnBpVffWjgeJjX https://accountnum11.com
cleos system regproducer accountnum12 EOS5EfU2fDgHZTNwPhuoHJgKcrNJ3PbyaYMHMrgMnBpVffWjgeJjX https://accountnum12.com
cleos system regproducer accountnum13 EOS5EfU2fDgHZTNwPhuoHJgKcrNJ3PbyaYMHMrgMnBpVffWjgeJjX https://accountnum13.com

cleos system listproducers

cleos system voteproducer prods accountnum11 accountnum11 accountnum12 accountnum13

cleos transfer eosio accountnum11 "9.0000 SYS"
cleos get info