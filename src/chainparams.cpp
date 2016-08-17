// Copyright (c) 2010 Satoshi Nakamoto
// Copyright (c) 2009-2014 The Bitcoin developers
// Copyright (c) 2014-2015 The Dash developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include "chainparams.h"

#include "assert.h"
#include "core.h"
#include "protocol.h"
#include "util.h"

#include <boost/assign/list_of.hpp>

using namespace boost::assign;

//
// Main network
//

/*
// -mainnet

input_script: 04ffff001d01044c6554686520436f6e766572736174696f6e2031382f4a756c2f3230313620426c6f636b636861696e20746563686e6f6c6f677920636f756c6420626520612067616d65206368616e67657220666f7220646576656c6f70696e6720636f6d6d756e6974696573
algorithm: X11
merkle hash: a442938ed81c7c1df8ebe7e97b4adc6456710c2ae104d8955f947ddcba1e49e3
pszTimestamp: The Conversation 18/Jul/2016 Blockchain technology could be a game changer for developing communities
pubkey: 04678afdb0fe5548271967f1a67130b7105cd6a828e03909a67962e0ea1f61deb649f6bc3f4cef38c4f35504e51ec112de5c384df7ba0b8d578a4c702b6bf11d5f
time: 1468837313
bits: 0x1e0ffff0
nonce: 880310
genesis hash: 0000015c110228d3769a7e213411a4cc4b9c6c8a24eefeea833c2a599f266fd3

// -Testnet

input_script: 04ffff001d01044c6554686520436f6e766572736174696f6e2031382f4a756c2f3230313620426c6f636b636861696e20746563686e6f6c6f677920636f756c6420626520612067616d65206368616e67657220666f7220646576656c6f70696e6720636f6d6d756e6974696573
algorithm: X11
merkle hash: a442938ed81c7c1df8ebe7e97b4adc6456710c2ae104d8955f947ddcba1e49e3
pszTimestamp: The Conversation 18/Jul/2016 Blockchain technology could be a game changer for developing communities
pubkey: 04678afdb0fe5548271967f1a67130b7105cd6a828e03909a67962e0ea1f61deb649f6bc3f4cef38c4f35504e51ec112de5c384df7ba0b8d578a4c702b6bf11d5f
time: 1468840512
bits: 0x1e0ffff0
nonce: 1801117
genesis hash: 000009a1550a7533bfce990194655098f096c55c011e628f5604be3fff43f67c

// -REGTEST
input_script: 04ffff001d01044c6554686520436f6e766572736174696f6e2031382f4a756c2f3230313620426c6f636b636861696e20746563686e6f6c6f677920636f756c6420626520612067616d65206368616e67657220666f7220646576656c6f70696e6720636f6d6d756e6974696573
algorithm: X11
merkle hash: a442938ed81c7c1df8ebe7e97b4adc6456710c2ae104d8955f947ddcba1e49e3
pszTimestamp: The Conversation 18/Jul/2016 Blockchain technology could be a game changer for developing communities
pubkey: 04678afdb0fe5548271967f1a67130b7105cd6a828e03909a67962e0ea1f61deb649f6bc3f4cef38c4f35504e51ec112de5c384df7ba0b8d578a4c702b6bf11d5f
time: 1468840698
bits: 0x1e0ffff0
nonce: 525719
genesis hash: 00000e75b4ff10d0d382c3d01952fed471f4c2d9047d4c9a6eefb4a4aa826ad2

화폐단위: CHP(CHIP)

base58Prefixes[PUBKEY_ADDRESS] = list_of( 11);                    // Gamblr addresses start with 'C'
base58Prefixes[SCRIPT_ADDRESS] = list_of( 06);                    // Gamblr script addresses start with '7'
base58Prefixes[SECRET_KEY] =     list_of(204w);                    // Gamblr private keys start with '7' or 'C'
base58Prefixes[EXT_PUBLIC_KEY] = list_of(35)(40)(47)(53);         // Gamblr BIP32 pubkeys start with 'chpv'
base58Prefixes[EXT_SECRET_KEY] = list_of(35)(40)(47)(47);         // Gamblr BIP32 prvkeys start with 'chpp'
base58Prefixes[EXT_COIN_TYPE]  = list_of(0x80000777);             // Gamblr BIP44 coin type is '777'
*/

unsigned int pnSeed[] =
{
    0x3210ce66, 0x3213747b, 0x1717ba83, 0x3210ce66, 0x3213747b,
    0x1715cc22, 0xbc8e2769, 0x36f8e397, 0x2a793a5b, 0x3251c027,
    0x05fe6003, 0xaf73c92c, 0xd035bf02, 0xc06f4182, 0xa2f32110,
};

class CMainParams : public CChainParams {
public:
    CMainParams() {
        // The message start string is designed to be unlikely to occur in normal data.
        // The characters are rarely used upper ASCII, not valid as UTF-8, and produce
        // a large 4-byte int at any alignment.
        pchMessageStart[0] = 0xbf;
        pchMessageStart[1] = 0x0c;
        pchMessageStart[2] = 0x6b;
        pchMessageStart[3] = 0xbd;
        vAlertPubKey = ParseHex("048240a8748a80a286b270ba126705ced4f2ce5a7847b3610ea3c06513150dade2a8512ed5ea86320824683fc0818f0ac019214973e677acd1244f6d0571fc5103");
        nDefaultPort = 7777;
        nRPCPort = 7776;
        bnProofOfWorkLimit = CBigNum(~uint256(0) >> 20);  // Dash starting difficulty is 1 / 2^12
        nSubsidyHalvingInterval = 210000;

        // Genesis block
        const char* pszTimestamp = "The Conversation 18/Jul/2016 Blockchain technology could be a game changer for developing communities";
        CTransaction txNew;
        txNew.vin.resize(1);
        txNew.vout.resize(1);
        txNew.vin[0].scriptSig = CScript() << 486604799 << CScriptNum(4) << vector<unsigned char>((const unsigned char*)pszTimestamp, (const unsigned char*)pszTimestamp + strlen(pszTimestamp));
        txNew.vout[0].nValue = 50 * COIN;
        txNew.vout[0].scriptPubKey = CScript() << ParseHex("04678afdb0fe5548271967f1a67130b7105cd6a828e03909a67962e0ea1f61deb649f6bc3f4cef38c4f35504e51ec112de5c384df7ba0b8d578a4c702b6bf11d5f") << OP_CHECKSIG;
        genesis.vtx.push_back(txNew);
        genesis.hashPrevBlock = 0;
        genesis.hashMerkleRoot = genesis.BuildMerkleTree();
        genesis.nVersion = 1;
        genesis.nTime    = 1468837313;
        genesis.nBits    = 0x1e0ffff0;
        genesis.nNonce   = 880310;

        hashGenesisBlock = genesis.GetHash();
        assert(hashGenesisBlock == uint256("0x0000015c110228d3769a7e213411a4cc4b9c6c8a24eefeea833c2a599f266fd3"));
        assert(genesis.hashMerkleRoot == uint256("0xa442938ed81c7c1df8ebe7e97b4adc6456710c2ae104d8955f947ddcba1e49e3"));

        vSeeds.push_back(CDNSSeedData("gamblr.cf", "dnsseed.gamblr.cf"));
        vSeeds.push_back(CDNSSeedData("gamblr.tk", "dnsseed.gamblr.tk"));
        vSeeds.push_back(CDNSSeedData("gamblr.ml", "dnsseed.gamblr.ml"));
        vSeeds.push_back(CDNSSeedData("gamblr.ga", "dnsseed.gamblr.ga"));
        vSeeds.push_back(CDNSSeedData("gamblr.gq", "dnsseed.gamblr.gq"));

        base58Prefixes[PUBKEY_ADDRESS] = list_of( 76);                    // Dash addresses start with 'X'
        base58Prefixes[SCRIPT_ADDRESS] = list_of( 16);                    // Dash script addresses start with '7'
        base58Prefixes[SECRET_KEY] =     list_of(204);                    // Dash private keys start with '7' or 'X'
        base58Prefixes[EXT_PUBLIC_KEY] = list_of(0x02)(0xFE)(0x52)(0xF8); // Dash BIP32 pubkeys start with 'drkv'
        base58Prefixes[EXT_SECRET_KEY] = list_of(0x02)(0xFE)(0x52)(0xCC); // Dash BIP32 prvkeys start with 'drkp'
        base58Prefixes[EXT_COIN_TYPE]  = list_of(0x80000005);             // Dash BIP44 coin type is '5'

        // Convert the pnSeeds array into usable address objects.
        for (unsigned int i = 0; i < ARRAYLEN(pnSeed); i++)
        {
            // It'll only connect to one or two seed nodes because once it connects,
            // it'll get a pile of addresses with newer timestamps.
            // Seed nodes are given a random 'last seen time' of between one and two
            // weeks ago.
            const int64_t nOneWeek = 7*24*60*60;
            struct in_addr ip;
            memcpy(&ip, &pnSeed[i], sizeof(ip));
            CAddress addr(CService(ip, GetDefaultPort()));
            addr.nTime = GetTime() - GetRand(nOneWeek) - nOneWeek;
            vFixedSeeds.push_back(addr);
        }
    }

    virtual const CBlock& GenesisBlock() const { return genesis; }
    virtual Network NetworkID() const { return CChainParams::MAIN; }

    virtual const vector<CAddress>& FixedSeeds() const {
        return vFixedSeeds;
    }
protected:
    CBlock genesis;
    vector<CAddress> vFixedSeeds;
};
static CMainParams mainParams;


//
// Testnet (v3)
//
class CTestNetParams : public CMainParams {
public:
    CTestNetParams() {
        // The message start string is designed to be unlikely to occur in normal data.
        // The characters are rarely used upper ASCII, not valid as UTF-8, and produce
        // a large 4-byte int at any alignment.
        pchMessageStart[0] = 0xce;
        pchMessageStart[1] = 0xe2;
        pchMessageStart[2] = 0xca;
        pchMessageStart[3] = 0xff;

        vAlertPubKey = ParseHex("04517d8a699cb43d3938d7b24faaff7cda448ca4ea267723ba614784de661949bf632d6304316b244646dea079735b9a6fc4af804efb4752075b9fe2245e14e412");
        nDefaultPort = 17777;
        nRPCPort = 17776;
        strDataDir = "testnet3";

        // Modify the testnet genesis block so the timestamp is valid for a later start.
        genesis.nTime = 1468840512;
        genesis.nNonce = 1801117;

        hashGenesisBlock = genesis.GetHash();
        assert(hashGenesisBlock == uint256("0x000009a1550a7533bfce990194655098f096c55c011e628f5604be3fff43f67c"));

        vFixedSeeds.clear();
        vSeeds.clear();
        /*
          vSeeds.push_back(CDNSSeedData("dashpay.io", "testnet-seed.dashpay.io"));
          vSeeds.push_back(CDNSSeedData("dash.qa", "testnet-seed.dash.qa"));
        */
        //legacy seeders
        /*
        vSeeds.push_back(CDNSSeedData("darkcoin.qa", "testnet-seed.darkcoin.qa"));
        vSeeds.push_back(CDNSSeedData("masternode.io", "test.dnsseed.masternode.io"));
        vSeeds.push_back(CDNSSeedData("darkcoin.io",  "testnet-seed.darkcoin.io"));
        */

        vSeeds.push_back(CDNSSeedData("gamblr.cf", "dnsseed.gamblr.cf"));
        vSeeds.push_back(CDNSSeedData("gamblr.tk", "dnsseed.gamblr.tk"));
        vSeeds.push_back(CDNSSeedData("gamblr.ml", "dnsseed.gamblr.ml"));
        vSeeds.push_back(CDNSSeedData("gamblr.ga", "dnsseed.gamblr.ga"));
        vSeeds.push_back(CDNSSeedData("gamblr.gq", "dnsseed.gamblr.gq"));


        base58Prefixes[PUBKEY_ADDRESS] = list_of(139);                    // Testnet dash addresses start with 'x' or 'y'
        base58Prefixes[SCRIPT_ADDRESS] = list_of( 19);                    // Testnet dash script addresses start with '8' or '9'
        base58Prefixes[SECRET_KEY]     = list_of(239);                    // Testnet private keys start with '9' or 'c' (Bitcoin defaults)
        base58Prefixes[EXT_PUBLIC_KEY] = list_of(0x3a)(0x80)(0x61)(0xa0); // Testnet dash BIP32 pubkeys start with 'DRKV'
        base58Prefixes[EXT_SECRET_KEY] = list_of(0x3a)(0x80)(0x58)(0x37); // Testnet dash BIP32 prvkeys start with 'DRKP'
        base58Prefixes[EXT_COIN_TYPE]  = list_of(0x80000001);             // Testnet dash BIP44 coin type is '5' (All coin's testnet default)
    }
    virtual Network NetworkID() const { return CChainParams::TESTNET; }
};
static CTestNetParams testNetParams;


//
// Regression test
//
class CRegTestParams : public CTestNetParams {
public:
    CRegTestParams() {
        pchMessageStart[0] = 0xfc;
        pchMessageStart[1] = 0xc1;
        pchMessageStart[2] = 0xb7;
        pchMessageStart[3] = 0xdc;
        nSubsidyHalvingInterval = 150;
        bnProofOfWorkLimit = CBigNum(~uint256(0) >> 1);
        genesis.nTime = 1468840698;
        genesis.nBits = 0x1e0ffff0;
        genesis.nNonce = 525719;
        nDefaultPort = 17774;
        strDataDir = "regtest";

        hashGenesisBlock = genesis.GetHash();
        assert(hashGenesisBlock == uint256("0x00000e75b4ff10d0d382c3d01952fed471f4c2d9047d4c9a6eefb4a4aa826ad2"));

        vSeeds.clear();  // Regtest mode doesn't have any DNS seeds.
    }

    virtual bool RequireRPCPassword() const { return false; }
    virtual Network NetworkID() const { return CChainParams::REGTEST; }
};
static CRegTestParams regTestParams;

static CChainParams *pCurrentParams = &mainParams;

const CChainParams &Params() {
    return *pCurrentParams;
}

void SelectParams(CChainParams::Network network) {
    switch (network) {
        case CChainParams::MAIN:
            pCurrentParams = &mainParams;
            break;
        case CChainParams::TESTNET:
            pCurrentParams = &testNetParams;
            break;
        case CChainParams::REGTEST:
            pCurrentParams = &regTestParams;
            break;
        default:
            assert(false && "Unimplemented network");
            return;
    }
}

bool SelectParamsFromCommandLine() {
    bool fRegTest = GetBoolArg("-regtest", false);
    bool fTestNet = GetBoolArg("-testnet", false);

    if (fTestNet && fRegTest) {
        return false;
    }

    if (fRegTest) {
        SelectParams(CChainParams::REGTEST);
    } else if (fTestNet) {
        SelectParams(CChainParams::TESTNET);
    } else {
        SelectParams(CChainParams::MAIN);
    }
    return true;
}
