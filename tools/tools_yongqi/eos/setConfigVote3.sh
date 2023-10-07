#! /bin/bash
set -x

#PUBKEY:EOS5EfU2fDgHZTNwPhuoHJgKcrNJ3PbyaYMHMrgMnBpVffWjgeJjX  <-> PRIVATEKEY:5HxK6mfoNr1pbnbYs1AmsKjavJQaoxiNVUdeJD6ZPFZkQvGcZVM
cleos system regproducer accountnum11 EOS5EfU2fDgHZTNwPhuoHJgKcrNJ3PbyaYMHMrgMnBpVffWjgeJjX https://accountnum11.com
cleos system regproducer accountnum12 EOS5EfU2fDgHZTNwPhuoHJgKcrNJ3PbyaYMHMrgMnBpVffWjgeJjX https://accountnum12.com
cleos system regproducer accountnum13 EOS5EfU2fDgHZTNwPhuoHJgKcrNJ3PbyaYMHMrgMnBpVffWjgeJjX https://accountnum13.com

cleos system voteproducer prods accountnum11 accountnum11 accountnum12 accountnum13

cleos get info