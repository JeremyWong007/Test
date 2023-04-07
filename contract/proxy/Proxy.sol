// SPDX-License-Identifier: UNLICENSED

pragma solidity ^0.8.0;
import "./ProxyStore.sol";
/**
    调用者合约，继承自己的存储合约
**/
contract Proxy is ProxyStore{
    fallback () external payable{
        (bool success, bytes memory res) = impl.delegatecall(msg.data);
        emit log(res);
    }
    function setImpl(address addr) public{
        impl = addr;
    }
}