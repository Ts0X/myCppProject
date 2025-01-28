#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <string>

// Function that attempts to crack the target hash using a dictionary attack
bool dictionaryAttack(const std::string& targetHash, const std::string& dictFile, const std::string& hashType);

// Function to handle user input and initiate the dictionary attack process
void Dictionary();

#endif // DICTIONARY_H
