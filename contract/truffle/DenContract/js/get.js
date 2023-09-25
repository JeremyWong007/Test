
var Store = artifacts.require('./Store.sol')
const { utils } = require("ethers")

// myTuple = [{
//     value1: 100,
//     value2: 100,
//     value3: "0xD2b53c6dcF4EB754DE108ec0420EE7EcfC1223B3",
//     value4:'abcdefg'
//  }]

async function main() {
    // const nft721Address = "0xEC6cB88dE71a1EB2ed7891954fBcaFB98504CacB";///eth
    const nft721Address = "0xD2b53c6dcF4EB754DE108ec0420EE7EcfC1223B3";///mcp

    const nft721 = await Store.at(nft721Address);
    
    // 1 test int uint 
    // const John721Balance = await nft721.getint(1);
    // console.log(John721Balance);
    // await nft721.getuint(100);
    // await nft721.getint8(100);
    // await nft721.getint40(100);
    // await nft721.getint64(100);
    // await nft721.getint128(100);

    // 2 test address and int
    // const John721Balance = await nft721.getaddressint(nft721Address);

    // 3 test address and int
    // const John721Balance = await nft721.getstringint("aa");

    // 4 test address and int
    //  var arrbool = [true,false,false,true,true];
    //  var arrint = [5,6];
    //  const John721Balance = await nft721.getintslice2(arrbool,arrint);

    // 5 test string slice
    // var arrstring = ["abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyz","b"];
    // var arrint = [5,6,7];
    // const John721Balance = await nft721.getstringslice(arrstring,arrint);
    // await nft721.getstringslice2(arrstring,arrint);

    // 6 test bytes slice
    // await nft721.getbytesslice('0x0102030405060708090a0b0c0d0e0f1112131415161718191a1b1c1d1e1f3a3b3c',5);
    // await nft721.getbytesslice2(['0x0102030405060708090a0b0c0d0e0f1112131415161718191a1b1c1d1e1f3a3b3c','0x5c'],5);
    // await nft721.getbytesslice3(['0x0102030405060708090a0b0c0d0e0f1112131415161718191a1b1c1d1e1f3a3b3c','0x5c'],5);
    // await nft721.getbytesslice4('0x010203',5);
    // await nft721.getbytesslice6(['0x010203','0x040506'],5);

    // 7 test trup
    ///gettrup1
    // await nft721.gettrup1([100,100, nft721Address,'abcdefg','0x0102030405060708090a0b0c0d0e0f1112131415161718191a1b1c1d1e1f3a3b3c'],5);
    ///gettrup2
    // var arrint1 = [1,2,3];///Dynamic
    // var arrint2 = [4,5];
    // const Address1 = "0xD2b53c6dcF4EB754DE108ec0420EE7EcfC1223B3";
    // const Address2 = "0x49a1b41e8ccb704f5c069ef89b08cd33f764e9b3";
    // const Address3 = "0xf0821dc4ba9419b865aa412170377ca3b44cdb58";
    // var arraddress1 = [Address1,Address2,Address3];   ///Dynamic
    // var arraddress2 = ["0x329e6b5b8e59fc73d892958b2ff6a89474e3d067","0x827cce78dc6ec7051f2d7bb9e7adaefba7ca3248"]; 
    // var arrstring1 = ["abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyz","abc","defgh"];///Dynamic
    // var arrstring2 = ["abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyz","aaa"];
    // var arrbytes1 = ['0x0102030405060708090a0b0c0d0e0f1112131415161718191a1b1c1d1e1f3a3b3c','0x5c','0x5d5e5f'];///Dynamic
    // var arrbytes2 = ['0x0102030405060708090a0b0c0d0e0f1112131415161718191a1b1c1d1e1f3a3b3c','0x6a6b6c'];
    // var arrbytes31 = ['0x010203','0x040506','0x0a0b0c'];///Dynamic
    // var arrbytes32 = ['0x212223','0x242526'];
    // await nft721.gettrup2(
    //     [arrint1,arrint2, arraddress1,arraddress2,arrstring1,arrstring2,arrbytes1,arrbytes2,arrbytes31,arrbytes32],
    //     5
    // );
    // ///gettrup3
    // var arrint73_1 = [1,2,3];///Dynamic
    // var arrstring73_1 = 'abc';
    // var st73_1 = [arrint73_1,arrstring73_1];
    // var arrint73_2 = [4,5];
    // var arrstring73_2 = 'def';
    // var st73_2 = [arrint73_2,arrstring73_2]
    // await nft721.gettrup3(
    //     [st73_1,st73_2],
    //     5
    // );

    // ///gettrup4
    // await nft721.gettrup4(
    //     [st73_1,st73_2],
    //     [arrint1,arrint2, arraddress1,arraddress2,arrstring1,arrstring2,arrbytes1,arrbytes2,arrbytes31,arrbytes32],
    // );

    ///////////////test unpack
    // ///  1 test return int,address,string,bool,bytes
    // // const g = await nft721.getreturns(1);
    // const Address = "0xD2b53c6dcF4EB754DE108ec0420EE7EcfC1223B3";
    // var bytes = '0x0a0b0c';
    // const g = await nft721.getreturns1(8,Address,"abcdefg",true,bytes);

    ////2 test return int,address,string,bool,bytes slice
    var int = 11;
    var arrint2 = [12,13];
    var arrint3 = [14,15,16];
    // const g = await nft721.getreturns21(int,arrint2,arrint3);     //int slice

    var address = "0xD2b53c6dcF4EB754DE108ec0420EE7EcfC1223B3"
    var arraddress2 = ["0x329e6b5b8e59fc73d892958b2ff6a89474e3d067","0x827cce78dc6ec7051f2d7bb9e7adaefba7ca3248"];
    var arraddress3 = ["0x49a1b41e8ccb704f5c069ef89b08cd33f764e9b3","0xf0821dc4ba9419b865aa412170377ca3b44cdb58","0xdab8a5fb82eb24ad321751bb2dd8e4cc9a4e45e5"];
    // const g = await nft721.getreturns22(address,arraddress2,arraddress3); //address slice

    var string = "abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyz111"
    var arrstring2 = ["abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyz222","abcde"];
    var arrstring3 = ["abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyz333","abc","defgh"];
    // const g = await nft721.getreturns23(string,arrstring2,arrstring3);    //string slice

    var bool = true;
    var arrbool2 = [true,false];
    var arrbool3 = [true,false,true];
    // const g = await nft721.getreturns24(bool,arrbool2,arrbool3);    //string slice

    var bytes = '0x0102030405060708090a0b0c0d0e0f1112131415161718191a1b1c1d1e1f3a3b3c010101';
    var arrbytes2 = ['0x0102030405060708090a0b0c0d0e0f1112131415161718191a1b1c1d1e1f3a3b3c020202','0x5c020202'];
    var arrbytes3 = ['0x0102030405060708090a0b0c0d0e0f1112131415161718191a1b1c1d1e1f3a3b3c','0x5c030303','0x5d5e5f030303'];
    // const g = await nft721.getreturns25(bytes,arrbytes2,arrbytes3);    //bytes slice

    var bytes3 = '0x010101';
    var arrbytes31 = ['0x020202','0x040506'];
    var arrbytes32 = ['0x030303','0x242526','0x0a0b0c'];
    // const g = await nft721.getreturns26(bytes3,arrbytes31,arrbytes32);    //bytes3 slice

    // const g = await nft721.getreturns27(arrint3,arraddress3,arrstring3,arrbool3,arrbytes3);    //all slice

    /// 3 test tuple
    // const g = await nft721.getreturnstuple([100,'0x329e6b5b8e59fc73d892958b2ff6a89474e3d067','abcdefg',true,'0x0102030405060708090a0b0c0d0e0f1112131415161718191a1b1c1d1e1f3a3b3c']);

     /// 3 st using slice test tuple
     var arrint131 = [1,2];
     var arraddress131 = ["0x329e6b5b8e59fc73d892958b2ff6a89474e3d067","0x827cce78dc6ec7051f2d7bb9e7adaefba7ca3248"]; 
     var arrstring131 = ["abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyz","aaa"];
     var arrbool131 = [true,false];
     var arrbytes131 = ['0x0102030405060708090a0b0c0d0e0f1112131415161718191a1b1c1d1e1f3a3b3c','0x6a6b6c'];
     var arrbytes3131 = ['0x212223','0x242526'];
    //  const g = await nft721.getreturnstuple2([arrint131,arraddress131, arrstring131, arrbool131,arrbytes131,arrbytes3131]); /// array

    //  const g = await nft721.getreturnstuple3([arrint131,arraddress131, arrstring131, arrbool131,arrbytes131,arrbytes3131]); ///slice

    const g = await nft721.Get();

    console.log(g);
    process.exit()
}

module.exports = main;