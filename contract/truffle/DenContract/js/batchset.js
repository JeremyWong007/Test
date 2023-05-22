var Store = artifacts.require('./BatchTransfer.sol')

async function main() {
    const nft721Address = "0xD2b53c6dcF4EB754DE108ec0420EE7EcfC1223B3";///mcp
    // const nft721Address = "0xfF719dAd583E6003E5307083D8B9B6935305702D";///eth

    const nft721 = await Store.at(nft721Address);
    const g = await nft721.deposit({value:"10000000000000000000000"});
    // const g = await nft721.deposit({value:"10000000000000000000"});//10 eth

    console.log(g);
    process.exit()
}

module.exports = main;