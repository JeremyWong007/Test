var Store = artifacts.require('./DENMinerDemo.sol')

async function main() {
    const nft721Address = "0xa381753F72673313D12046f1A29c007b2eeB7316";///mcp
    // const nft721Address = "0xfF719dAd583E6003E5307083D8B9B6935305702D";///eth

    const nft721 = await Store.at(nft721Address);

    const g = await nft721.setParam(80000);
    
    console.log(g);
    process.exit()
}

module.exports = main;