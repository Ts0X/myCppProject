#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include "dictionary.h"
#include "hash_Functions.h"

using namespace std;

bool dictionaryAttack(const string& targetHash, const string& dictFile, const string& hashType) {
    ifstream file(dictFile);
    if (!file.is_open()) {
        cout << "Failed to open dictionary file!" << endl;
        return false;
    }

    string word;
    while (getline(file, word)) {
        // Trim whitespace from the word (optional)
        word.erase(remove_if(word.begin(), word.end(), ::isspace), word.end());

        string hash;

        // Select hashing method based on the hashType argument
        if (hashType == "MD5") {
            hash = md5(word);
        } else if (hashType == "SHA-1") {
            hash = sha1(word);
        } else if (hashType == "SHA-224") {
            hash = sha224(word);
        } else if (hashType == "SHA-256") {
            hash = sha256(word);
        } else if (hashType == "SHA-384") {
            hash = sha384(word);
        } else if (hashType == "SHA-512") {
            hash = sha512(word);
        }

        // Compare generated hash with the target hash
        if (hash == targetHash) {
            cout << "Match found: " << word << endl;
            return true;
        }
    }

    return false;
}

void Dictionary() {
    string targetHash, dictFile, hashType;

    cout << "\tEnter the hash to crack: " << endl;
    getline(cin, targetHash);

    cout << "\tEnter dictionary file path: " << endl;
    getline(cin, dictFile);

    cout << "\tEnter hash type (e.g. MD5, SHA-1): " << endl;
    getline(cin, hashType);
    
    // Convert the string to uppercase
    transform(hashType.begin(), hashType.end(), hashType.begin(), ::toupper);

    if (dictionaryAttack(targetHash, dictFile, hashType)) {
        cout << "!!Hash cracked successfully!!" << endl;
    } else {
        cout << "No match found." << endl;
    }           
}
