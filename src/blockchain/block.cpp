//
// Created by Barney Randall on 14/10/2020.
//

#include <sstream>
#include "../../inc/blockchain/block.h"
#include "../../inc/crypto/sha256.h"

Block::Block(const uint64_t index, const string &data, const string& prevHash) :
    index(index),
    data(data),
    prevHash(prevHash)
{
    nonce = -1;
    timestamp = time(nullptr);
}

void Block::MineBlock(const uint32_t difficulty)
{
    char cstr[difficulty + 1];
    for (uint32_t i = 0; i < difficulty; ++i) {
        cstr[i] = '0';
    }
    cstr[difficulty] = '\0';

    string str = string(cstr);

    do {
        nonce++;
        hash = CalculateHash();
    } while(hash.substr(0, difficulty) != str);

    cout << "Block mined: " << hash << endl;
}

const time_t Block::GetTimestamp() const
{
    return timestamp;
}

const string Block::GetHash() const
{
    return hash;
}

const string Block::GetPrevHash() const
{
    return prevHash;
}

// Create a hash for this block using its contents and the previous blocks hash
const string Block::CalculateHash() const
{
    stringstream ss;
    ss << index << time << data << nonce << prevHash;

    return sha256(ss.str());
}




