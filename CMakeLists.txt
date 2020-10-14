cmake_minimum_required(VERSION 3.17)
project(ShtCoin)

set(CMAKE_CXX_STANDARD 14)

add_executable(ShtCoin src/main.cpp inc/blockchain/block.h inc/blockchain/blockchain.h inc/crypto/sha256.h src/crypto/sha256.cpp src/blockchain/block.cpp src/blockchain/blockchain.cpp)