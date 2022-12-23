// SPDX-License-Identifier: UNLICENSED

pragma solidity ^0.8.0;

import "@openzeppelin/contracts/token/ERC20/ERC20.sol";

contract Testsol {
    address erc = 0x6c4250a0EEE4D6056935b1965B392D6E77306768;

    uint256 temp = 0;

    event log1(uint256 t);

    function trsToAddr(address addr, uint256 amount) public {
        ERC20(erc).transferFrom(msg.sender, addr, amount);
    }

    function trsToAddr2(address addr, uint256 amount) public {
        ERC20(erc).transferFrom(msg.sender, addr, amount);
        ERC20(erc).transferFrom(msg.sender, addr, amount);
    }

    function trsToAddr3(address addr, uint256 amount) public {
        ERC20(erc).transferFrom(msg.sender, addr, amount);
        ERC20(erc).transferFrom(msg.sender, addr, amount);
        ERC20(erc).transferFrom(msg.sender, addr, amount);
    }

    function trans(address payable addr) public payable {
        addr.transfer(msg.value);
    }

    function getTemp() public view returns (uint256) {
        return temp;
    }

    function setTemp(uint256 t) public {
        temp = t;
        emit log1(t);
    }
}