var Store = artifacts.require('./DENMinerDemo.sol')

async function main() {
    const nft721Address = "0xa381753F72673313D12046f1A29c007b2eeB7316";///mcp
    // const nft721Address = "0xfF719dAd583E6003E5307083D8B9B6935305702D";///eth

    const nft721 = await Store.at(nft721Address);

    // var addresses = ["0xba618c1e3e90d16e6c15d92ed198780dc4ad39c2","0xc543a3868f3613eecd109761f71e31832ecf51ba"];
    // var values = ["1","2"];

    //var address = "0x1144B522F45265C2DFDBAEE8E324719E63A1694C";
    var address = "0xbA0f222294bc5FB6Ff3b494cCBF55570818d3A62";
    //var address = "0x64B660664C5916335231374BF390DF7eE2d49Dd7";
    //var address = "0x7FB37c436BC662E055a20B022bDB056599DA08Fd";
    //var address = "0xbA0f222294bc5FB6Ff3b494cCBF55570818d3A62";
    //var address = "0xc543a3868f3613eecd109761f71e31832ecf51ba";
    //var address = "0xba618c1e3e90d16e6c15d92ed198780dc4ad39c2";
    //var address = "0xfF719dAd583E6003E5307083D8B9B6935305702D";
    const g = await nft721.stake(80000, {value:"80000", from: accounts[0]});

    //const g = await nft721.withdraw();

    console.log(g);
    process.exit()
}

module.exports = main;