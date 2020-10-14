//
// Created by Barney Randall on 14/10/2020.
//

#ifndef SHTCOIN_BLOCKCHAIN_H
#define SHTCOIN_BLOCKCHAIN_H

#include <vector>

#include "block.h"

using namespace std;

class Blockchain {
public:
    Blockchain();

    void AddBlock(const string& data);

private:
    const Block GetLastBlock() const;

private:
    uint32_t difficulty;
    vector<Block> blockchain;
};

#endif //SHTCOIN_BLOCKCHAIN_H
