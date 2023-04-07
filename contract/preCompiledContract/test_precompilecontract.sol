// SPDX-License-Identifier: MIT
pragma solidity ^0.8.0;

contract Test {
    event log(string s);
    address addr;

       //这个函数用来连接两个字符串 'aaa' + 'bbb' =>  'aaabbb'
    function strConcat(string memory _a, string memory _b) public pure returns (string memory){
        bytes memory _ba = bytes(_a);
        bytes memory _bb = bytes(_b);
        string memory ret = new string(_ba.length + _bb.length);
        bytes memory bret = bytes(ret);
        uint k = 0;
        for (uint i = 0; i < _ba.length; i++) bret[k++] = _ba[i];
        for (uint i = 0; i < _bb.length; i++) bret[k++] = _bb[i];
        return string(ret);
    }    
    
    //这个函数最关键，比较取巧，用来将uint256类型的 0-9 数字转成字符
    function toStr(uint256 value) public pure returns(string memory) {
        bytes memory alphabet = "0123456789abcdef";
        //这里把数字转成了bytes32类型，但是因为我们知道数字是 0-9 ，所以前面其实都是填充了0
        bytes memory data = abi.encodePacked(value);
        bytes memory str = new bytes(1);
        //所以最后一位才是真正的数字
        uint i = data.length - 1;
        str[0] = alphabet[uint(uint8(data[i] & 0x0f))];
        return string(str);
    }
    
    //调用这个函数，通过取模的方式，一位一位转换
    function uintToString(uint _uint) public pure returns (string memory str) {
 
        if(_uint==0) return '0';
 
        while (_uint != 0) {
            //取模
            uint remainder = _uint % 10;
            //每取一位就移动一位，个位、十位、百位、千位……
            _uint = _uint / 10;
            //将字符拼接，注意字符位置
            str = strConcat(toStr(remainder),str);
        }
    }

    function toAsciiString(address x) internal pure returns (string memory) {
        bytes memory s = new bytes(40);
        for (uint i = 0; i < 20; i++) {
            bytes1 b = bytes1(uint8(uint(uint160(x)) / (2**(8*(19 - i)))));
            bytes1 hi = bytes1(uint8(b) / 16);
            bytes1 lo = bytes1(uint8(b) - 16 * uint8(hi));
            s[2*i] = char(hi);
            s[2*i+1] = char(lo);            
        }
        return string(s);
    }

    function char(bytes1 b) internal pure returns (bytes1 c) {
        if (uint8(b) < 10) return bytes1(uint8(b) + 0x30);
        else return bytes1(uint8(b) + 0x57);
    }

    function setMaxStake(uint v) public {
        string memory value = uintToString(v);
        string memory str = strConcat("MaxStake:", value);
        emit log(str);
    }

    function WitelistAdd(address den) public {
        string memory addr = toAsciiString(den);
        string memory str = strConcat("WitelistAdd:",addr);
        emit log(str);
    }

    function Stake(address den, uint v) public {
        string memory addr = toAsciiString(den);
        string memory str = strConcat("Stake:", addr);
        str = strConcat(str, ";");
        str = strConcat(str, uintToString(v));
        emit log(str);
    }

    function CalculateRewards(address den) public returns(uint[2] memory amount){
        uint[2] memory input;
        addr = den;
        input[0] = uint256(uint160(den));
        input[1] = block.timestamp;
        //input[1] = 0x12345678;

        assembly {
        if iszero(staticcall(40000, 0x09, input, 0x40, amount, 0x10)) {
            revert(0,0)
            }
        }
    }

    // function callNew(uint v, uint r, uint s, uint hash) public view returns(uint256[1] memory p) {
    //     // address signer = ecrecover(hash, v, r, s);
    //     // require(signer != address(0), "ECDSA: invalid signature");
    //     address addr = 0xDE4552Ff8350B967aC5Ff77f29C707C417ef2B37;
    //     uint256 aa = uint256(addr);
    //     uint256[4] memory input;
    //     input[0] = uint256(addr);
    //     input[1] = v;
    //     input[2] = r;
    //     input[3] = s;

    //     assembly {
    //     if iszero(staticcall(40000, 0x09, input, 0x40, p, 0x20)) {
    //         revert(0,0)
    //         }   
    //     }
    // }

    function sha25622(bytes memory data) public returns (bytes32) {
        bytes32 hash;
        assembly {
            if iszero(call(not(0), 0x2, 0, add(data, 0x20), mload(data), hash, 0x20)) {
                revert(0, 0)
            }
        }
        return hash;
    }
}