// SPDX-License-Identifier: UNLICENSED

pragma solidity ^0.8.0;
import "./ImplV2Store.sol";
/**
    实现合约 V2，继承自己的存储合约
**/
contract ImplV2 is ImplV2Store{
    function addT() public payable {
        t = t + 2;
    }
    function getT() public returns (uint res){
        return t;
    }
}
