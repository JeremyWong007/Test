#!/bin/bash

key=$(cat wallet_eos.key)
cleos wallet unlock --password $key
