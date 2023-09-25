// SPDX-License-Identifier: MIT
pragma solidity ^0.8.0;


// The contract is named DENMinerDemo
contract DENMinerDemo {


    // Address of the owner of the contract
    address public owner;


    // Struct for miners, which holds the maximum stake and the stake amount
    struct Miner {
        uint256 maxStake;
        uint256 stakeAmount;
    }


    // Global struct, which holds the maximum stake and the maximum reward per day
    struct Global {
        uint256 maxStake;
        uint256 maxRewardPerDay;
    }


    // Mapping to store the whitelist status of miners
    mapping(address => bool) witeListMapping;
    // Mapping to store information about miners
    mapping(address => Miner) minerInfo;


    // Global variable to store the maximum stake and the maximum reward per day
    Global global;


    // Define events for logging actions
    event UpdateGlobalMaxStake(uint256 oldMaxStake, uint256 newMaxStake);
    event SetParam(uint256 maxRewardPerDay);
    event AddMiner(address minerAddress);
    event DeleteMiner(address minerAddress);
    event Stake(address minerAddress, uint256 stakeAmount, uint256 maxStake);
    event Unstake(address minerAddress, uint256 unstakeAmount);


    // Constructor to initialize maximum stake and maximum reward per day values
    constructor(uint256 maxStake_, uint256 maxRewardPerDay_) {
        owner = msg.sender;
        global = Global({
            maxStake: maxStake_,
            maxRewardPerDay: maxRewardPerDay_
        });
    }


    // Function to return global information (maxStake and maxRewardPerDay)
    function getGlobalInfo() public view returns(Global memory) {
        return global;
    }


    // Function to return stake information of a miner
    function getPledgeInfo(address minerAddress) public view returns(Miner memory) {
        return minerInfo[minerAddress];
    }


    // Function to update the maximum global stake
    function updateGlobalMaxStake(uint256 newMaxStake) public onlyOwner {
        require(newMaxStake > 0, "newMaxStake must be greater than 0.");
        uint256 _oldMaxStake = global.maxStake;
        require(newMaxStake != _oldMaxStake, "Invalid update.");
        global.maxStake = newMaxStake;
       
        emit UpdateGlobalMaxStake(_oldMaxStake, newMaxStake);
    }


    // Function to set the maximum daily reward
    function setParam(uint256 maxRewardPerDay) public onlyOwner {
        require(maxRewardPerDay > 0, "maxRewardPerDay must be greater than 0.");
        uint256 _oldMaxStake = global.maxStake;
        require(maxRewardPerDay != _oldMaxStake, "Invalid update.");
        global.maxStake = maxRewardPerDay;
       
        emit SetParam(maxRewardPerDay);
    }


    // Function to check if an address is a miner (whitelisted)
    function isMiner(address minerAddress) public view returns(bool) {
        return witeListMapping[minerAddress];
    }


    // Function to add a miner to the whitelist
    function addMiner(address minerAddress) public onlyOwner {
        require(!witeListMapping[minerAddress], "Failed to add, already added to the whitelist.");
        witeListMapping[minerAddress] = true;


        emit AddMiner(minerAddress);
    }


    // Function to remove a miner from the whitelist
    function deleteMiner(address minerAddress) public onlyOwner {
        require(witeListMapping[minerAddress], "Failed to delete, the address does not exist in the whitelist.");
        witeListMapping[minerAddress] = false;


        emit DeleteMiner(minerAddress);
    }


    // Function for miners to stake their tokens
    function stake(uint256 stakeAmount) public onlyMiner payable {
        require(msg.value == stakeAmount && stakeAmount == global.maxStake, "The amount entered is incorrect.");
        require(minerInfo[msg.sender].stakeAmount == 0, "Already staked.");
        minerInfo[msg.sender] = Miner({
            stakeAmount: stakeAmount,
            maxStake: global.maxStake
        });


        emit Stake(msg.sender, stakeAmount, global.maxStake);
    }


    // Function for miners to unstake their tokens
    function unstake() public onlyMiner {
        Miner memory _miner = minerInfo[msg.sender];
        require(_miner.stakeAmount > 0, "No stake amount.");


        uint256 amountToSend = _miner.stakeAmount;


        // Reset the Miner's stake to zero
        delete minerInfo[msg.sender].stakeAmount;


        require(
            payable(msg.sender).send(amountToSend) == true,
            "Unstake failed."
        );


        emit Unstake(msg.sender, amountToSend);
    }


    // Modifier to allow only the contract owner to call certain functions
    modifier onlyOwner() {
        require(msg.sender == owner, "Only owner can call this function.");
        _;
    }


    // Modifier to allow only whitelisted miners to call certain functions
    modifier onlyMiner() {
        require(witeListMapping[msg.sender], "Only whitelisted miners can call this function.");
        _;
    }
}

