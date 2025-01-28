#include <iostream>
#include <string>
#include <algorithm>
#include <cctype> 
#include "hashidentify.h"
using namespace std;

// Function to check if a string is a valid hexadecimal
bool isHexadecimal(const string& str) {
    return all_of(str.begin(), str.end(), [](unsigned char c) { return isxdigit(c); });
}

/* Function for hash identification.
   The user enters the encrypted message, and the machine identifies it based on the length of the hash. */
void identify() {
    string GetHash;
    cout << "Enter the Hash: " << endl;
    getline(cin, GetHash);

    // Check if the input is a valid hexadecimal string
    if (!isHexadecimal(GetHash)) {
        cout << "Invalid hash format. Please enter a valid hexadecimal string." << endl;
        return;
    }

    // Convert to lowercase for consistency (optional)
    string lowerHash = GetHash;
    transform(lowerHash.begin(), lowerHash.end(), lowerHash.begin(), ::tolower);

    // Identify hash type based on length
    switch (GetHash.length()) {
        case 32: 
            cout << "Looks like MD5" << endl; 
            break;
        case 40: 
            cout << "Looks like SHA-1 or RIPEMD-160" << endl; 
            break;
        case 56: 
            cout << "Looks like SHA-224 or SHA-3-224" << endl; 
            break;
        case 64: 
            cout << "Looks like SHA-256 or SHA-3-256" << endl; 
            break;
        case 96: 
            cout << "Looks like SHA-384 or SHA-3-384" << endl; 
            break;
        case 128: 
            cout << "Looks like SHA-512 or SHA-3-512 or Whirlpool" << endl; 
            break;
        case 48: 
            cout << "Looks like Tiger" << endl; 
            break;
        case 8:  
            cout << "Looks like CRC32" << endl; 
            break;
        default: 
            cout << "Unknown hash type" << endl; 
            break;
    }
}
