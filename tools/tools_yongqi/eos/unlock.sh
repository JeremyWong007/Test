#!/bin/bash

key=$(cat /data/info/wallet_eos.key)
cleos --url wallet unlock --password $key
