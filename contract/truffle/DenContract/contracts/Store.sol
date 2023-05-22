// SPDX-License-Identifier: MIT
pragma solidity >=0.4.22 <0.9.0;

// contract Store {

//     /**
//      * 声明了public，会自动创建getter函数
//      * function stores(address account) external view returns (string) {
//      *     return stores[account];
//      * }
//      */

//     // /// 1 test int uint 
//     // mapping (int => int) public intstores;
//     // function setint(int value) public {
//     //     intstores[value]=value;
//     // }
//     // function getint(int value) view public returns(int) {
//     //     return  intstores[value];
//     // }
//     // function getuint(uint value) pure public returns(uint) {
//     //     return  value;
//     // }
//     // function getint8(int8 value) pure public returns(int8) {
//     //     return  value;
//     // }
//     // function getint40(int40 value) pure public returns(int40) {
//     //     return  value;
//     // }
//     // function getint64(int64 value) pure public returns(int64) {
//     //     return  value;
//     // }
//     // function getint128(int128 value) pure public returns(int128) {
//     //     return  value;
//     // }

//     // /// 2 test address and int
//     // mapping (address => int) public addressintstores;
//     // function setaddressint(address a,int value,int b,int c,bool add) public {
//     //     if (add){
//     //         addressintstores[a]=value + b + c;
//     //     }
//     //     else{
//     //         addressintstores[a]=value;
//     //     }
//     // }
//     // function getaddressint(address a) view public returns(int) {
//     //     return addressintstores[a];
//     // }

//     // /// 3 test string and int
//     // mapping (string => int) public stringintstores;
//     // function setstringint(string memory a,int value) public {
//     //     stringintstores[a]=value;
//     // }
//     // function getstringint(string memory a) view public returns(int) {
//     //     return stringintstores[a];
//     // }

//     // /// 4 test bool and int slice
//     // function getintslice(bool[] memory a, uint[] memory b) public pure {///dynamically
//     // }
//     // function getintslice2(bool[5] memory a, uint[2] memory b) public pure {///static arrays,not dynamically
//     // }

//     // /// 5 test string slice
//     // function getstringslice(string[] memory a,uint[] memory b) public pure {
//     // }
//     // function getstringslice2(string[2] memory a,uint[3] memory b) public pure {
//     // }

//     // /// 6 test bytes slice
//     // function getbytesslice(bytes memory a,uint b) public pure {
//     // }
//     // function getbytesslice2(bytes[] memory a,uint b) public pure {
//     // }
//     // function getbytesslice3(bytes[2] memory a,uint b) public pure {
//     // }
//     // function getbytesslice4(bytes3 a,uint b) public pure {
//     // }
//     // function getbytesslice5(bytes3[] memory a,uint b) public pure {
//     // }
//     // function getbytesslice6(bytes3[2] memory a,uint b) public pure {
//     // }


//     // /// 7 test trup
//     // struct st1 {
//     //     int value1;
//     //     int128 value2;
//     //     address value3;
//     //     string value4;
//     //     bytes   value5;
//     // }
//     // function gettrup1(st1 memory v1,int valueint) public pure {}
//     // struct st2 {
//     //     int[] valueint1;       ///Dynamic
//     //     int[2] valueint2;
//     //     address[] valueaddress1;   ///Dynamic
//     //     address[2] valueaddress2;
//     //     string[] valuestring1;    ///Dynamic
//     //     string[2] valuestring2;
//     //     bytes[] valuebytes1;     ///Dynamic
//     //     bytes[2] valuebytes2;
//     //     bytes3[] valuebytes31;    ///Dynamic
//     //     bytes3[2] valuebytes32;
//     // }
//     // function gettrup2(st2 memory v1,int valueint) public pure {}///tuple slice

//     // struct st3 {
//     //     int[] valueint1;       ///Dynamic
//     //     string value4;
//     // }
//     // function gettrup3(st3[] memory v1,int valueint) public pure {}///tuple slice

//     // function gettrup4(st3[] memory v1,st2 memory v2) public pure {}///tuple slice


//     // /////////////////////////////test decode
//     // // / 1 test return int,address,string,bool,bytes
//     // function getreturns1(int v1,address v2,string memory v3,bool v4, bytes memory v5) pure public returns(int,address,string memory,bool, bytes memory) {
//     //     return  (v1,v2,v3,v4,v5);
//     // }

//     // ////2 test return int,address,string,bool,bytes slice and array
//     // function getreturns21(int v1, int[2] memory v2, int[] memory v3) pure public returns(int, int[2] memory, int[] memory) {
//     //     return (v1,v2,v3);
//     // }
//     // function getreturns22(address v1,address[2] memory v2, address[] memory v3) pure public returns(address,address[2] memory, address[] memory) {
//     //     return  (v1,v2,v3);
//     // }
//     // function getreturns23(string memory v1, string[2] memory v2, string[] memory v3) pure public returns(string memory, string[2] memory, string[] memory) {
//     //     return  (v1,v2,v3);
//     // }
//     // function getreturns24(bool v1, bool[2] memory v2, bool[] memory v3) pure public returns(bool, bool[2] memory, bool[] memory) {
//     //     return  (v1,v2,v3);
//     // }
//     // function getreturns25(bytes memory v1, bytes[2] memory v2, bytes[] memory v3) pure public returns(bytes memory, bytes[2] memory, bytes[] memory) {
//     //     return  (v1,v2,v3);
//     // }
//     // function getreturns26(bytes3 v1, bytes3[2] memory v2, bytes3[] memory v3) pure public returns(bytes3, bytes3[2] memory, bytes3[] memory) {
//     //     return  (v1,v2,v3);
//     // }
//     // function getreturns27(int[] memory v1,address[] memory v2,string[] memory v3,bool[] memory v4, bytes[] memory v5) pure public returns(int[] memory,address[] memory,string[] memory,bool[] memory, bytes[] memory) {
//     //     return  (v1,v2,v3,v4,v5);
//     // }

//     // /// 3 test tuple
//     // struct st4 {
//     //     int  intstores;
//     //     address  addressstores;
//     //     string  stringstores;
//     //     bool  boolstores;
//     //     bytes  bytesstores;
//     // }
//     // function getreturnstuple(st4 memory v1) pure public returns(st4 memory) {
//     //     return  v1;
//     // }
//     // struct st5 {
//     //     int[2]  intstores;
//     //     address[2]  addressstores;
//     //     string[2]  stringstores;
//     //     bool[2]  boolstores;
//     //     bytes[2]  bytesstores;
//     //     bytes3[2]  bytes3stores;
//     // }
//     // function getreturnstuple2(st5 memory v1) pure public returns(st5 memory) {
//     //     return  v1;
//     // }

//     // struct st6 {
//     //     int[]  intstores;
//     //     address[]  addressstores;
//     //     string[]  stringstores;
//     //     bool[]  boolstores;
//     //     bytes[]  bytesstores;
//     //     bytes3[]  bytes3stores;
//     // }
//     // function getreturnstuple3(st6 memory v1) pure public returns(st6 memory) {
//     //     return  v1;
//     // }
// }

contract owned {
    constructor() { owner = msg.sender; }
    address owner;

    modifier onlyOwner {
        require(msg.sender == owner);
        _;
    }
}

contract Store is owned {
    int public intstores;
    function Set(int value) public onlyOwner {
        intstores = value;
    }
    function Get() view public returns(int) {
        return  intstores;
    }
}





