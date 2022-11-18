/*
编译：
g++ main.cpp -o test
g++ main.cpp -o test -g  增加调试信息
*/

#include <iostream>

#define HELLO "Nice"
#pragma message(_CRT_STRINGIZE(HELLO))

#define INIT_CASES                              \
                                                \
    static const void* const jumpTable[256] = { \
        &&STOP, /* 00 */                        \
        &&ADD,                                  \
        &&MUL,                                  \
        &&SUB,                                  \
        &&DIV,                                  \
        &&SDIV,                                 \
        &&MOD,                                  \
        &&SMOD,                                 \
        &&ADDMOD,                               \
        &&MULMOD,                               \
        &&EXP,                                  \
        &&SIGNEXTEND,                           \
        &&INVALID,                              \
        &&INVALID,                              \
        &&INVALID,                              \
        &&INVALID,                              \
        &&LT, /* 10, */                         \
        &&GT,                                   \
        &&SLT,                                  \
        &&SGT,                                  \
        &&EQ,                                   \
        &&ISZERO,                               \
        &&AND,                                  \
        &&OR,                                   \
        &&XOR,                                  \
        &&NOT,                                  \
        &&BYTE,                                 \
        &&SHL,                                  \
        &&SHR,                                  \
        &&SAR,                                  \
        &&INVALID,                              \
        &&INVALID,                              \
        &&SHA3, /* 20, */                       \
        &&INVALID,                              \
        &&INVALID,                              \
        &&INVALID,                              \
        &&INVALID,                              \
        &&INVALID,                              \
        &&INVALID,                              \
        &&INVALID,                              \
        &&INVALID,                              \
        &&INVALID,                              \
        &&INVALID,                              \
        &&INVALID,                              \
        &&INVALID,                              \
        &&INVALID,                              \
        &&INVALID,                              \
        &&INVALID,                              \
        &&ADDRESS, /* 30, */                    \
        &&BALANCE,                              \
        &&ORIGIN,                               \
        &&CALLER,                               \
        &&CALLVALUE,                            \
        &&CALLDATALOAD,                         \
        &&CALLDATASIZE,                         \
        &&CALLDATACOPY,                         \
        &&CODESIZE,                             \
        &&CODECOPY,                             \
        &&GASPRICE,                             \
        &&EXTCODESIZE,                          \
        &&EXTCODECOPY,                          \
        &&RETURNDATASIZE,                       \
        &&RETURNDATACOPY,                       \
        &&EXTCODEHASH,                          \
        &&BLOCKHASH, /* 40, */                  \
        &&INVALID,  /* &&COINBASE, */           \
        &&TIMESTAMP,                            \
        &&NUMBER,                               \
        &&INVALID, /* &&DIFFICULTY,  */         \
        &&INVALID, /* &&GASLIMIT,    */         \
        &&CHAINID,                              \
        &&SELFBALANCE,                          \
        &&INVALID,                              \
        &&INVALID,                              \
        &&INVALID,                              \
        &&INVALID,                              \
        &&INVALID,                              \
        &&INVALID,                              \
        &&INVALID,                              \
        &&INVALID,                              \
        &&POP, /* 50, */                        \
        &&MLOAD,                                \
        &&MSTORE,                               \
        &&MSTORE8,                              \
        &&SLOAD,                                \
        &&SSTORE,                               \
        &&JUMP,                                 \
        &&JUMPI,                                \
        &&PC,                                   \
        &&MSIZE,                                \
        &&GAS,                                  \
        &&JUMPDEST,                             \
        &&BEGINDATA,                            \
        &&BEGINSUB,                             \
        &&INVALID,                              \
        &&INVALID,                              \
        &&PUSH1, /* 60, */                      \
        &&PUSH2,                                \
        &&PUSH3,                                \
        &&PUSH4,                                \
        &&PUSH5,                                \
        &&PUSH6,                                \
        &&PUSH7,                                \
        &&PUSH8,                                \
        &&PUSH9,                                \
        &&PUSH10,                               \
        &&PUSH11,                               \
        &&PUSH12,                               \
        &&PUSH13,                               \
        &&PUSH14,                               \
        &&PUSH15,                               \
        &&PUSH16,                               \
        &&PUSH17, /* 70, */                     \
        &&PUSH18,                               \
        &&PUSH19,                               \
        &&PUSH20,                               \
        &&PUSH21,                               \
        &&PUSH22,                               \
        &&PUSH23,                               \
        &&PUSH24,                               \
        &&PUSH25,                               \
        &&PUSH26,                               \
        &&PUSH27,                               \
        &&PUSH28,                               \
        &&PUSH29,                               \
        &&PUSH30,                               \
        &&PUSH31,                               \
        &&PUSH32,                               \
        &&DUP1, /* 80, */                       \
        &&DUP2,                                 \
        &&DUP3,                                 \
        &&DUP4,                                 \
        &&DUP5,                                 \
        &&DUP6,                                 \
        &&DUP7,                                 \
        &&DUP8,                                 \
        &&DUP9,                                 \
        &&DUP10,                                \
        &&DUP11,                                \
        &&DUP12,                                \
        &&DUP13,                                \
        &&DUP14,                                \
        &&DUP15,                                \
        &&DUP16,                                \
        &&SWAP1, /* 90, */                      \
        &&SWAP2,                                \
        &&SWAP3,                                \
        &&SWAP4,                                \
        &&SWAP5,                                \
        &&SWAP6,                                \
        &&SWAP7,                                \
        &&SWAP8,                                \
        &&SWAP9,                                \
        &&SWAP10,                               \
        &&SWAP11,                               \
        &&SWAP12,                               \
        &&SWAP13,                               \
        &&SWAP14,                               \
        &&SWAP15,                               \
        &&SWAP16,                               \
        &&LOG0, /* A0, */                       \
        &&LOG1,                                 \
        &&LOG2,                                 \
        &&LOG3,                                 \
        &&LOG4,                                 \
        &&INVALID,                              \
        &&INVALID,                              \
        &&INVALID,                              \
        &&INVALID,                              \
        &&INVALID,                              \
        &&INVALID,                              \
        &&INVALID,                              \
        &&PUSHC,                                \
        &&JUMPC,                                \
        &&JUMPCI,                               \
        &&INVALID,                              \
        &&JUMPTO, /* B0, */                     \
        &&JUMPIF,                               \
        &&JUMPSUB,                              \
        &&JUMPV,                                \
        &&JUMPSUBV,                             \
        &&BEGINSUB,                             \
        &&BEGINDATA,                            \
        &&RETURNSUB,                            \
        &&PUTLOCAL,                             \
        &&GETLOCAL,                             \
        &&INVALID,                              \
        &&INVALID,                              \
        &&INVALID,                              \
        &&INVALID,                              \
        &&INVALID,                              \
        &&INVALID,                              \
        &&INVALID, /* C0, */                    \
        &&XADD,                                 \
        &&XMUL,                                 \
        &&XSUB,                                 \
        &&XDIV,                                 \
        &&XSDIV,                                \
        &&XMOD,                                 \
        &&XSMOD,                                \
        &&INVALID,                              \
        &&INVALID,                              \
        &&INVALID,                              \
        &&INVALID,                              \
        &&INVALID,                              \
        &&INVALID,                              \
        &&INVALID,                              \
        &&INVALID,                              \
        &&XLT, /* D0 */                         \
        &&XGT,                                  \
        &&XSLT,                                 \
        &&XSGT,                                 \
        &&XEQ,                                  \
        &&XISZERO,                              \
        &&XAND,                                 \
        &&XOOR,                                 \
        &&XXOR,                                 \
        &&XNOT,                                 \
        &&INVALID,                              \
        &&XSHL,                                 \
        &&XSHR,                                 \
        &&XSAR,                                 \
        &&XROL,                                 \
        &&XROR,                                 \
        &&XPUSH, /* E0, */                      \
        &&XMLOAD,                               \
        &&XMSTORE,                              \
        &&INVALID,                              \
        &&XSLOAD,                               \
        &&XSSTORE,                              \
        &&XVTOWIDE,                             \
        &&XWIDETOV,                             \
        &&XGET,                                 \
        &&XPUT,                                 \
        &&XSWIZZLE,                             \
        &&XSHUFFLE,                             \
        &&INVALID,                              \
        &&INVALID,                              \
        &&INVALID,                              \
        &&INVALID,                              \
        &&CREATE, /* F0, */                     \
        &&CALL,                                 \
        &&CALLCODE,                             \
        &&RETURN,                               \
        &&DELEGATECALL,                         \
        &&CREATE2,                              \
        &&INVALID,                              \
        &&INVALID,                              \
        &&INVALID,                              \
        &&INVALID,                              \
        &&STATICCALL,                           \
        &&INVALID,                              \
        &&INVALID,                              \
        &&REVERT,                               \
        &&INVALID,                              \
        &&SELFDESTRUCT,                         \
    };

using namespace std;

class Copyable {
public:
    Copyable(){}
    Copyable(const Copyable &o) {
        cout << "Copied" << endl;
    }
};
Copyable ReturnRvalue() {
    return Copyable(); //返回一个临时对象
}
void AcceptVal(Copyable a) {

}
void AcceptRef(const Copyable& a) {

}

int main() {
    cout<<"Hello world!"<<endl;
    cout << "pass by value: " << endl;
    AcceptVal(ReturnRvalue()); // 应该调用两次拷贝构造函数
    cout << "pass by reference: " << endl;
    AcceptRef(ReturnRvalue()); //应该只调用一次拷贝构造函数
    cout << HELLO << endl;
    if(0)
        cout<<"hello line"<<endl; cout<<"line2"<<endl;
    return 0;
}