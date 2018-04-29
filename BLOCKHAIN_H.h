#ifndef BC_CLASS_H
#define BC_CLASS_H

#include <iostream>
#include <string>
#include <ctime>
#include "MD5_H.h"

using namespace std;
MD5 md5;
class BlockChain {

public:
	BlockChain(string, string); /* <-- Promises the class that a constructor is present */
	static int blockId;
	string previousHash;
	string inputData;
        string dateTime;
        string currentHash = createHash();


	/* Class method to return current date and time. */
	string returnDateTime() {
		time_t result = time(nullptr);
		string dateTime = asctime(localtime(&result));
		return dateTime;
	}

	/* Class method to return the hash of the current block. */
	string returnPrevHash() { return previousHash; }

	/* Class method to return the input data of the current block */
	string returnInputData() { return inputData; }
    
    /* Class method to create Block's hash value */
    string createHash(){
        dateTime = returnDateTime();
        string hashValue = (BlockChain::previousHash+BlockChain::inputData+dateTime);
        char *cHashValue = new char[hashValue.size()+1]; /* Casting the data of the block to a char */
        strcpy (cHashValue,hashValue.c_str());           /* this lets us hash it using the an algorithm */
        return md5.digestString(cHashValue);
	delete [] cHashValue;                            /* prevents memory leakage */
    }

};

/* Class Constructor */
BlockChain::BlockChain(string prevHash, string inpData) : previousHash(prevHash), inputData(inpData) {
	BlockChain::blockId = BlockChain::blockId + 1;}

/* Function to create genesis (first) block */
string genesisBlock() {return (md5.digestString("Fidget the very fast Midget1234"));}
#endif
