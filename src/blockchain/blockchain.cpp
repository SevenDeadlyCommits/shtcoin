//
// Created by Barney Randall on 14/10/2020.
//

#include "../../inc/blockchain/block.h"
#include "../../inc/blockchain/blockchain.h"

Blockchain::Blockchain()
{
    blockchain.emplace_back(Block(0, "Genesis Block", ""));
    difficulty = 6;
}

void Blockchain::AddBlock(const string& data)
{
    Block block = Block(blockchain.size(), data, GetLastBlock().GetHash());
    block.MineBlock(difficulty);
    blockchain.push_back(block);
}

const Block Blockchain::GetLastBlock() const
{
    return blockchain.back();
}