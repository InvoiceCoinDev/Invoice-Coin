// Copyright (c) 2010 Satoshi Nakamoto
// Copyright (c) 2009-2012 The Bitcoin developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include "assert.h"

#include "chainparams.h"
#include "main.h"
#include "util.h"

#include <boost/assign/list_of.hpp>

using namespace boost::assign;

struct SeedSpec6 {
    uint8_t addr[16];
    uint16_t port;
};

#include "chainparamsseeds.h"

// Convert the pnSeeds6 array into usable address objects.
static void convertSeed6(std::vector<CAddress> &vSeedsOut, const SeedSpec6 *data, unsigned int count)
{
    // It'll only connect to one or two seed nodes because once it connects,
    // it'll get a pile of addresses with newer timestamps.
    // Seed nodes are given a random 'last seen time' of between one and two
    // weeks ago.
    const int64_t nOneWeek = 7*24*60*60;
    for (unsigned int i = 0; i < count; i++)
    {
        struct in6_addr ip;
        memcpy(&ip, data[i].addr, sizeof(ip));
        CAddress addr(CService(ip, data[i].port));
        addr.nTime = GetTime() - GetRand(nOneWeek) - nOneWeek;
        vSeedsOut.push_back(addr);
    }
}

//
// Main network
//
class CMainParams : public CChainParams {
public:
    CMainParams() {
        // The message start string is designed to be unlikely to occur in normal data.
        // The characters are rarely used upper ASCII, not valid as UTF-8, and produce
        // a large 4-byte int at any alignment.
        pchMessageStart[0] = 0x7f;
        pchMessageStart[1] = 0xaa;
        pchMessageStart[2] = 0x11;
        pchMessageStart[3] = 0xc2;
        vAlertPubKey = ParseHex("00a111199f8d6caaf63e330ebfa1207275d71cb009f201c118b00cf8e77641c7f1e491443ba909842c009af375c0f5c1c7368e8d7e2066168c40ce3cb629cf212f");
        nDefaultPort = 10877;
        nRPCPort = 10879;
        bnProofOfWorkLimit = CBigNum(~uint256(0) >> 16);
        bnProofOfStakeLimit = CBigNum(~uint256(0) >> 20);

        const char* pszTimestamp = "A Simple Invoicing System Can Save You from Getting Stiffed by a Club | Gabe Yont | October 16, 2018";
        std::vector<CTxIn> vin;
        vin.resize(1);
        vin[0].scriptSig = CScript() << 0 << CBigNum(42) << vector<unsigned char>((const unsigned char*)pszTimestamp, (const unsigned char*)pszTimestamp + strlen(pszTimestamp));
        std::vector<CTxOut> vout;
        vout.resize(1);
        vout[0].nValue = 1 * COIN;
        vout[0].SetEmpty();
        CTransaction txNew(1, 1539691200, vin, vout, 0);
        genesis.vtx.push_back(txNew);
        genesis.hashPrevBlock = 0;
        genesis.hashMerkleRoot = genesis.BuildMerkleTree();
        genesis.nVersion = 1;
        genesis.nTime    = 1539691200; // Mon, 01 May 2017 00:00:00 GMT
        genesis.nBits    = bnProofOfWorkLimit.GetCompact();
        genesis.nNonce   = 30986;

        /** Genesis Block MainNet */
        /*
            Hashed MainNet Genesis Block Output
            block.hashMerkleRoot == 5591de6ebbe269216ca07c10e59a032ee85fae8a8048e0c62020e1e2d50cdc9d
            block.nTime = 1539691200
            block.nNonce = 30986
            block.GetHash = 00007e134c93ada85c3e422030a99e30ec2f42b4b5ed08ea4ef1ccd282954e92
        */

        hashGenesisBlock = genesis.GetHash();
        assert(hashGenesisBlock == uint256("0x00007e134c93ada85c3e422030a99e30ec2f42b4b5ed08ea4ef1ccd282954e92"));
        assert(genesis.hashMerkleRoot == uint256("0x5591de6ebbe269216ca07c10e59a032ee85fae8a8048e0c62020e1e2d50cdc9d"));

        base58Prefixes[PUBKEY_ADDRESS] = std::vector<unsigned char>(1,103);
        base58Prefixes[SCRIPT_ADDRESS] = std::vector<unsigned char>(1,91);
        base58Prefixes[SECRET_KEY] =     std::vector<unsigned char>(1,92);
        base58Prefixes[STEALTH_ADDRESS] = std::vector<unsigned char>(1,94);
        base58Prefixes[EXT_PUBLIC_KEY] = list_of(0x04)(0x88)(0xB2)(0x1E).convert_to_container<std::vector<unsigned char> >();
        base58Prefixes[EXT_SECRET_KEY] = list_of(0x04)(0x88)(0xAD)(0xE4).convert_to_container<std::vector<unsigned char> >();

        //vSeeds.push_back(CDNSSeedData("node1",  "127.0.0.1"));
        //vSeeds.push_back(CDNSSeedData("node2",  "127.0.0.1"));
        convertSeed6(vFixedSeeds, pnSeed6_main, ARRAYLEN(pnSeed6_main));

        nPoolMaxTransactions = 9;
        strMNenginePoolDummyAddress = "iGrwXgFQbhiSBsxVSSCeQmty2qzCt4uS7Q";
        nEndPoWBlock = 200;
        nStartPoSBlock = 0;
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
// Testnet
//
class CTestNetParams : public CMainParams {
public:
    CTestNetParams() {
        // The message start string is designed to be unlikely to occur in normal data.
        // The characters are rarely used upper ASCII, not valid as UTF-8, and produce
        // a large 4-byte int at any alignment.
        pchMessageStart[0] = 0x7f;
        pchMessageStart[1] = 0xbb;
        pchMessageStart[2] = 0x22;
        pchMessageStart[3] = 0xc2;
        bnProofOfWorkLimit = CBigNum(~uint256(0) >> 14);
        bnProofOfStakeLimit = CBigNum(~uint256(0) >> 18);
        vAlertPubKey = ParseHex("00b111199f8d6caaf63e330ebfa1207275d71cb009f201c118b00cf8e77641c7f1e491443ba909842c009af375c0f5c1c7368e8d7e2066168c40ce3cb629cf212f");
        nDefaultPort = 10437;
        nRPCPort = 10439;
        strDataDir = "testnet";

        // Modify the testnet genesis block so the timestamp is valid for a later start.
        genesis.nTime    = 1539691200+30;
        genesis.nBits  = bnProofOfWorkLimit.GetCompact();
        genesis.nNonce = 29964;

        /** Genesis Block TestNet */
        /*
            Hashed TestNet Genesis Block Output
            block.hashMerkleRoot == 5591de6ebbe269216ca07c10e59a032ee85fae8a8048e0c62020e1e2d50cdc9d
            block.nTime = 1539691230
            block.nNonce = 29964
            block.GetHash = 000320a8c6fb9ffa0affdcf95b1bc5745f9a52377197293099e4e626400be786
        */

        hashGenesisBlock = genesis.GetHash();
        assert(hashGenesisBlock == uint256("0x000320a8c6fb9ffa0affdcf95b1bc5745f9a52377197293099e4e626400be786"));

        vFixedSeeds.clear();
        vSeeds.clear();

        base58Prefixes[PUBKEY_ADDRESS] = std::vector<unsigned char>(1,102);
        base58Prefixes[SCRIPT_ADDRESS] = std::vector<unsigned char>(1,92);
        base58Prefixes[SECRET_KEY]     = std::vector<unsigned char>(1,91);
        base58Prefixes[STEALTH_ADDRESS] = std::vector<unsigned char>(1,93);
        base58Prefixes[EXT_PUBLIC_KEY] = list_of(0x04)(0x35)(0x87)(0xCF).convert_to_container<std::vector<unsigned char> >();
        base58Prefixes[EXT_SECRET_KEY] = list_of(0x04)(0x35)(0x83)(0x94).convert_to_container<std::vector<unsigned char> >();

        nEndPoWBlock = 0x7fffffff;
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
        pchMessageStart[0] = 0x7f;
        pchMessageStart[1] = 0xcc;
        pchMessageStart[2] = 0x33;
        pchMessageStart[3] = 0xc2;
        bnProofOfWorkLimit = CBigNum(~uint256(0) >> 1);
        genesis.nTime = 1539691200+90;
        genesis.nBits  = bnProofOfWorkLimit.GetCompact();
        genesis.nNonce = 8;
        hashGenesisBlock = genesis.GetHash();
        nDefaultPort = 10300;
        strDataDir = "regtest";

        /** Genesis Block RegNet */
        /*
            Hashed RegNet Genesis Block Output
            block.hashMerkleRoot == 5591de6ebbe269216ca07c10e59a032ee85fae8a8048e0c62020e1e2d50cdc9d
            block.nTime = 1539691290
            block.nNonce = 8
            block.GetHash = f29313f5d7eadbc0bc25f8bef54c81bd08c8da3edcc6606335e324ae7a38e8b9
        */

        assert(hashGenesisBlock == uint256("0xf29313f5d7eadbc0bc25f8bef54c81bd08c8da3edcc6606335e324ae7a38e8b9"));

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
