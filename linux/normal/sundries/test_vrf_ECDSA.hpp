/*
编译安装lsecp256k1-vrf: 
  git clone https://github.com/aergoio/secp256k1-vrf
    $ ./autogen.sh
    $ ./configure
    $ make
    $ make check
    $ sudo make install  # optional
*/

#include <secp256k1-vrf.h>
#include "../common.h"
#include <string.h>


class test_vrf_ECDSA
{
private:
    /* data */
public:
    test_vrf_ECDSA(/* args */);
    ~test_vrf_ECDSA();
};

test_vrf_ECDSA::test_vrf_ECDSA(/* args */)
{
    ilog("test_vrf_ECDSA in");
    secp256k1_context *sender;
    secp256k1_context *receiver;
    sender   = secp256k1_context_create(SECP256K1_CONTEXT_SIGN | SECP256K1_CONTEXT_VERIFY);
    receiver = secp256k1_context_create(SECP256K1_CONTEXT_SIGN | SECP256K1_CONTEXT_VERIFY);
    unsigned char proof[81]={0};
    unsigned char seckey[32]={0x27,0xcb,0xce,0xe3,0x63,0x28,0xfc,0xd9,0x3b,0x08,0x4e,0xad,0x7f,0x30,0x00,0x2c,0x69,0x9f,0x65,0x4f,0xa9,0x2e,0x08,0x91,0xbf,0x61,0xa2,0x61,0xf0,0x4b,0xa9,0x2e};
    secp256k1_pubkey pubkey={0xc2,0x14,0x9a,0x96,0x9a,0xf7,0x95,0xa0,0x44,0xcd,0x30,0x67,0x2a,0xd1,0xa7,0xd4,0x8e,0x23,0x83,0xb5,0x29,0x73,0x20,0xb8,0x4d,0xb9,0xd8,0x9a,0x92,0x3d,0x9c,0x02,
        0xc1,0xd3,0x09,0xa4,0x92,0xee,0x9f,0xd6,0xf1,0x17,0xfe,0x50,0x3e,0x0b,0x19,0x56,0xac,0x42,0x01,0x7f,0xea,0x50,0xbf,0x77,0xca,0x78,0x60,0x2a,0x02,0xff,0x56,0xad};
    unsigned char pk[33]={0};
    size_t pklen=33;
    char msg[3]={0x11,0x22,0x33};
    unsigned char output[32]={0};
    secp256k1_pubkey pubkey2;
    memset(pubkey2.data, 0, sizeof(pubkey2.data));
    if(secp256k1_ec_pubkey_create(sender, &pubkey2, seckey) == 1){

    }

    if(secp256k1_ec_pubkey_serialize(sender, pk, &pklen, &pubkey2, SECP256K1_EC_COMPRESSED) == 1){
        ilog("secp256k1_ec_pubkey_serialize ok");
    }
    if(secp256k1_vrf_prove(proof,seckey,&pubkey2,msg,sizeof(msg)) == 1){
        ilog("secp256k1_vrf_prove ok");
    }
    else{
        ilog("secp256k1_vrf_prove fail");
    }
    if(secp256k1_vrf_verify(output,proof,pk,msg,sizeof(msg)) == 1){
        ilog("secp256k1_vrf_verify ok");
    }
    else{
        ilog("secp256k1_vrf_verify fail");
    }
}

test_vrf_ECDSA::~test_vrf_ECDSA()
{
}
