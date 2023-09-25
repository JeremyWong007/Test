#!/bin/bash

key=$(cat wallet_eos_1.key)
cleos wallet unlock --password $key
