// Copyright (c) 2009-2010 Satoshi Nakamoto
// Copyright (c) 2009-2018 The Bitcoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include <primitives/block.h>

#include <hash.h>
#include <tinyformat.h>
#include <util/strencodings.h>
#include <crypto/common.h>

uint256 CBlockHeader::GetHash() const
{
    #if defined(WORDS_BIGENDIAN)
            uint8_t data[80];
            WriteLE32(&data[0], nVersion);
            memcpy(&data[4], hashPrevBlock.begin(), hashPrevBlock.size());
            memcpy(&data[36], hashMerkleRoot.begin(), hashMerkleRoot.size());
            WriteLE32(&data[68], nTime);
            WriteLE32(&data[72], nBits);
            WriteLE32(&data[76], nNonce);
            return HashQuark(data, data + 80);
    #else // Can take shortcut for little endian    
        return HashQuark(BEGIN(nVersion), END(nNonce));
    #endif    
}

std::string CBlock::ToString() const
{
    std::stringstream s;
    s << strprintf("CBlock(hash=%s, ver=0x%08x, hashPrevBlock=%s, hashMerkleRoot=%s, nTime=%u, nBits=%08x, nNonce=%u, vtx=%u)\n",
        GetHash().ToString(),
        nVersion,
        hashPrevBlock.ToString(),
        hashMerkleRoot.ToString(),
        nTime, nBits, nNonce,
        vtx.size());
    for (const auto& tx : vtx) {
        s << "  " << tx->ToString() << "\n";
    }
    return s.str();
}
