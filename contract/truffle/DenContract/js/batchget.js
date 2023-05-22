var Store = artifacts.require('./BatchTransfer.sol')

async function main() {
    const nft721Address = "0xD2b53c6dcF4EB754DE108ec0420EE7EcfC1223B3";///mcp
    // const nft721Address = "0xfF719dAd583E6003E5307083D8B9B6935305702D";///eth

    const nft721 = await Store.at(nft721Address);

    var addresses = ["0xba618c1e3e90d16e6c15d92ed198780dc4ad39c2","0xc543a3868f3613eecd109761f71e31832ecf51ba"];
    var values = ["1","2"];
    const g = await nft721.batchTransfer(addresses,values);

    //const g = await nft721.withdraw();

    console.log(g);
    process.exit()
}

module.exports = main;