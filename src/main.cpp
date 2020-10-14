
#include <string>
#include "../inc/blockchain/blockchain.h"

int main() {

    Blockchain blockchain = Blockchain();

    for(int i = 0; i < 5; ++i) {
        cout << "Adding new block" << endl;
        string data = "Data in block ";
        blockchain.AddBlock(data);
    }

    return 0;
}
