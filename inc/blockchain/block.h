//
// Created by Barney Randall on 14/10/2020.
//

#ifndef SHTCOIN_BLOCK_H
#define SHTCOIN_BLOCK_H

#include <cstdint>
#include <iostream>

using namespace std;

class Block {
public:
    Block(const uint64_t index, const string& data, const string& prevHash);

    const string GetHash() const;

    const string GetPrevHash() const;

    const time_t GetTimestamp() const;

    // Actually 'mine' block, i.e. do the work
    // Potentially move this out of the block class
    void MineBlock(const uint32_t difficulty);

private:
    // Calculate a hash for this block
    const string CalculateHash() const;

private:
    // Data stored in this block
    string data;
    // Generated hash for this block
    string hash;
    // Previous blocks hash, used as part of CalculateHash function
    string prevHash;
    // Block index in chain
    uint64_t index;
    // Nonce value
    int64_t nonce;
    // Time block was created
    time_t timestamp;
};

#endif //SHTCOIN_BLOCK_H
