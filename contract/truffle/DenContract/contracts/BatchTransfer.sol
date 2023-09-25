// SPDX-License-Identifier: MIT
pragma solidity ^0.8.0;

contract BatchTransfer {
    address public owner;
    uint256 public depositedAmount;

    event EventDeposit(address indexed _from);
    event EventTransfer(address indexed _from, address[] recipients, uint256[] amounts);

    // 设置合约部署者为合约所有者
    constructor() {
        owner = msg.sender;
    }

    // 仅限合约所有者调用的修饰符
    modifier onlyOwner() {
        require(msg.sender == owner, "Only owner can call this function.");
        _;
    }

    // 存款功能
    function deposit() public payable onlyOwner {
        depositedAmount += msg.value;
        emit EventDeposit(msg.sender);
    }

    // 批量转账功能
    function batchTransfer(address[] memory recipients, uint256[] memory amounts) public onlyOwner {
        require(recipients.length == amounts.length, "Recipients and amounts arrays must have the same length.");

        uint256 totalAmount = 0;
        for (uint256 i = 0; i < amounts.length; i++) {
            totalAmount += amounts[i];
        }

        require(depositedAmount >= totalAmount, "The deposited amount is not enough to cover the transfers.");

        for (uint256 i = 0; i < recipients.length; i++) {
            address recipient = recipients[i];
            uint256 amount = amounts[i];

            (bool success, ) = recipient.call{value: amount}("");
            require(success, "Transfer failed.");

            depositedAmount -= amount;
        }

        emit EventTransfer(msg.sender, recipients, amounts);
    }

    // 允许合约所有者提取合约中的ETH余额
    function withdraw() public onlyOwner {
        uint256 amountToWithdraw = address(this).balance;
        depositedAmount = 0;

        (bool success, ) = owner.call{value: amountToWithdraw}("");
        require(success, "Withdraw failed.");
    }
}
