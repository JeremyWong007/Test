// var Store = artifacts.require('./Store.sol')
// var Store = artifacts.require('./BatchTransfer.sol')
var Store = artifacts.require('./DENMinerDemo.sol')

module.exports = function(deployer) {
    deployer.deploy(Store)
}

///eth
module.exports = function(deployer, network, accounts) {
    deployer.deploy(Store, 10000, 10000, {from: accounts[0]})
}