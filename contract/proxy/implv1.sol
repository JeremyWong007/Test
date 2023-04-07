// SPDX-License-Identifier: UNLICENSED

pragma solidity ^0.8.0;
import "./ImplV1Store.sol";
/**
    实现合约 V1，继承自己的存储合约
**/
contract ImplV1 is ImplV1Store{
    event log1(string s);
    // 
    function addT() public payable {
        t = t + 1;
        emit log1("ImplV1 addT");
    }

    function getT() public returns (uint res){
        emit log1("ImplV1 getT");
        return t;
    }

}
