var Store = artifacts.require('./Store.sol')

async function main() {
    // const nft721Address = "0xEC6cB88dE71a1EB2ed7891954fBcaFB98504CacB";///eth
    const nft721Address = "0xD2b53c6dcF4EB754DE108ec0420EE7EcfC1223B3";///mcp

    const nft721 = await Store.at(nft721Address);
    
    ///test int uint 
    // const g = await nft721.setint(10);

    ///test address and int
    // const g = await nft721.setaddressint(nft721Address,1,2,3,true);

    // /test address and int
    // const g = await nft721.setstringint("aa",9);

    //////////////test unpack
    /// 1 test return int,address,string,bool,bytes
    // const Address = "0xD2b53c6dcF4EB754DE108ec0420EE7EcfC1223B3";
    // var bytes = '0x0a0b0c';
    // const g = await nft721.setreturns(1,8,Address,"abcdefg",true,bytes);

    await nft721.Set(509);

    // console.log(g);
    process.exit()
}

module.exports = main;