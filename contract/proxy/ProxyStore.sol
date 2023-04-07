// SPDX-License-Identifier: UNLICENSED

pragma solidity ^0.8.0;
//将存储单独拆1个合约(不需要部署)，方便进行继承
contract ProxyStore {
    address public impl;
    event log(bytes);
}