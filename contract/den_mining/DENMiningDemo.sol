// SPDX-License-Identifier: MIT
pragma solidity ^0.8.0;
contract DENMinerDemo {




    // Contract owner address
    address public owner;




    // Miner struct to store stake amount
    struct Miner {
        uint256 maxStake;
        uint256 stakeAmount;
    }




    // Global struct to store maxStake and maxRewardPerDay
    struct Global {
        uint256 maxStake;
        uint256 maxRewardPerDay;
    }




    // Mapping to store miners' whitelist status
    mapping(address => bool) witeListMapping;
    // Mapping to store miners' information
    mapping(address => Miner) minerInfo;




    // Global variable to store maxStake and maxRewardPerDay
    Global global;




    // Events for logging actions
    event UpdateGlobalMaxStake(uint256 oldMaxStake, uint256 newMaxStake);
    event AddMiner(address indexed minerAddress);
    event DeleteMiner(address indexed minerAddress);
    event Stake(address indexed minerAddress, uint256 stakeAmount);
    event Unstake(address indexed minerAddress, uint256 unstakeAmount);




    // Constructor to initialize maxStake and maxRewardPerDay values
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




    // Function to return pledge (stake) information of a miner
    function getPledgeInfo(address minerAddress) public view returns(Miner memory) {
        return minerInfo[minerAddress];
    }


    function updateGlobalMaxStake(uint256 newMaxStake) public onlyOwner {
        require(newMaxStake > 0, "newMaxStaken must be greater than 0.");
        uint256 _oldMaxStake = global.maxStake;
        require(newMaxStake != _oldMaxStake, "Invalid update.");
        global.maxStake = newMaxStake;
       
        emit UpdateGlobalMaxStake(_oldMaxStake, newMaxStake);
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




    // Function to delete a miner from the whitelist
    function deleteMiner(address minerAddress) public onlyOwner {
        require(witeListMapping[minerAddress], "Deletion failed because the whitelist does not exist.");
        witeListMapping[minerAddress] = false;




        emit DeleteMiner(minerAddress);
    }




    // Function for miners to stake their tokens
    function stake(uint256 stakeAmount) public onlyMiner payable {
        require(msg.value == stakeAmount && stakeAmount == global.maxStake, "The amount entered is incorrect.");
        require(minerInfo[msg.sender].stakeAmount == 0, "Already pledged.");
        // minerInfo[msg.sender].stakeAmount = stakeAmount;
        // minerInfo[msg.sender].maxStake = global.maxStake;
        minerInfo[msg.sender] = Miner({
            stakeAmount: stakeAmount,
            maxStake: global.maxStake
        });
        // require(minerInfo[msg.sender].stakeAmount <= global.maxStake);




        emit Stake(msg.sender, stakeAmount);
    }




    // Function for miners to unstake their tokens
    function unstake() public onlyMiner {
        Miner memory _miner = minerInfo[msg.sender];
        require(_miner.stakeAmount > 0, "No pledge amount.");




        uint256 amountToSend = _miner.stakeAmount;




        // Reset the Miner to zero
        delete minerInfo[msg.sender].stakeAmount;




        require(
            payable(msg.sender).send(amountToSend) == true,
            "Unstake failed."
        );




        emit Unstake(msg.sender, amountToSend);
    }




    // Modifier to allow only the contract owner to call certain functions
    modifier onlyOwner() {
        require(msg.sender == owner, "Only owner can call.");
        _;
    }




    // Modifier to allow only whitelisted miners to call certain functions
    modifier onlyMiner() {
        require(witeListMapping[msg.sender], "Only miner can call.");
        _;
    }




}
