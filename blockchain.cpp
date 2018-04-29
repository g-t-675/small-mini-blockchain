#include <map>
#include "BLOCKCHAIN_H.h"

using namespace std;

/* Sets the Class' blockId, to be stored as the key in the map */
int BlockChain::blockId = 0;

/* Creates struct data structure, to be stored as the value in the map */
struct blockData {
	string currentHash;
	string inpData;
	string dateTime;
} currentBlock;

int main() {
        /* Creates map, similar to Python's dictionary to match a key with a value */
	map <int, blockData> blockList;     /* The value, in this case, is the struct created on lines 8-12 */


	int blockNum;
    cout << "How many blocks do you wish to create?" << endl;
	cin >> blockNum;
	
        /* Creates Genesis block's hash */
	string prevHash = genesisBlock();
	string inpData = "1234";
    
    /* Adds Genesis Block's data to maps struct */
    blockList[BlockChain::blockId].currentHash = prevHash;
    blockList[BlockChain::blockId].inpData = inpData;
    time_t result = time(nullptr);
    blockList[BlockChain::blockId].dateTime = asctime(localtime(&result));
    
    
	for (int i; i < blockNum+1; ++i) {
                
		BlockChain x (prevHash, inpData); /* Creates a new instance for the next block */
                
		/* Saves new block's data to the struct in the map */
		blockList[BlockChain::blockId].currentHash = x.createHash();
		blockList[BlockChain::blockId].inpData = x.returnInputData();
		blockList[BlockChain::blockId].dateTime = x.dateTime;
                
		/* sets the previous has (hash to be used to create a new instance) to the hash of the current block */
		prevHash = blockList[BlockChain::blockId].currentHash;

        
	}
	/* Prints a block of the user's choosing. */
    cout << "What block do you wish to view?" << endl;
    cin >> blockNum;
    cout << "The hash for block " << blockNum <<" is: "<< blockList[blockNum].currentHash << endl;
    cout << "It's data is: " << blockList[blockNum].inpData << endl;
    cout << "Finally, it was created on: " << blockList[blockNum].dateTime <<endl;
    
	return 0;
}
