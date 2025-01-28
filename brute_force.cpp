#include <iostream>
#include "brute_force.h"
#include "hash_Functions.h" // Make sure this header file exists
#include <string>
#include <cmath>
#include <conio.h> // For kbhit() and getch()
using namespace std;

// Recursive function to generate and check all combinations
void bruteForceRecursive(const string& crack, string current, int maxLen, const string& target, const string& hashType, long long& attempts, long long totalAttempts) {
    if (_kbhit()) { 
        char ch = _getch();  
        if (ch == 's' || ch == 'S') {
            cout << "Attempts so far: " << attempts << " / " << totalAttempts << endl;
        }
    }

    if (current.length() == maxLen) {
        attempts++;
        std::string hashAttempt;

        if (hashType == "md5") {
            hashAttempt = md5(current);
        } else if (hashType == "sha1") {
            hashAttempt = sha1(current);
        } else if (hashType == "sha224") {
            hashAttempt = sha224(current);
        } else if (hashType == "sha256") {
            hashAttempt = sha256(current);
        } else if (hashType == "sha384") {
            hashAttempt = sha384(current);
        } else if (hashType == "sha512") {
            hashAttempt = sha512(current);
        }

        if (hashAttempt == target) {
            cout << "Password found: " << current << endl;
            exit(0);
        }
        return;
    }

    for (char c : crack) {
        bruteForceRecursive(crack, current + c, maxLen, target, hashType, attempts, totalAttempts);
    }
}

void BruteForce() {
    string AB = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string ab = "abcdefghijklmnopqrstuvwxyz";
    string symbols = "~`@#$%^&*()_+-={[]}:;'<,>.?/|";
    string numbers = "1234567890";
    string crack = "";
    char answer;
    string encryptedForDecrypted;
    string hashType;

    // Input for the encrypted hash
    cout << "Enter the encrypted hash to brute force: " << endl;
    getline(cin, encryptedForDecrypted);

    // Input for the hash type
    cout << "Enter hash type (md5, sha1, sha224, sha256, sha384, sha512): " << endl;
    getline(cin, hashType);

    // Ask about character types to include
    cout << "Include A-Z? (y/n): " << endl;
    cin >> answer;
    cin.ignore();
    if (tolower(answer) == 'y') crack += AB;

    cout << "Include a-z? (y/n): " << endl;
    cin >> answer;
    cin.ignore();
    if (tolower(answer) == 'y') crack += ab;

    cout << "Include 0-9? (y/n): " << endl;
    cin >> answer;
    cin.ignore();
    if (tolower(answer) == 'y') crack += numbers;

    cout << "Include symbols? (y/n): " << endl;
    cin >> answer;
    cin.ignore();
    if (tolower(answer) == 'y') crack += symbols;

    int minLen, maxLen;

    // Show all characters for brute force
    cout << "All chars for brute force: " << crack << endl;

    cout << "Min length for password: " << endl;
    cin >> minLen;
    cin.ignore();

    cout << "Max length: " << endl;
    cin >> maxLen;
    cin.ignore();

    // Calculate total attempts
    long long totalAttempts = 0;
    for (int len = minLen; len <= maxLen; ++len) {
        totalAttempts += pow(crack.length(), len);
    }

    cout << "Total possible attempts: " << totalAttempts << endl;

    long long attempts = 0;

    // Start brute force
    for (int len = minLen; len <= maxLen; ++len) {
        bruteForceRecursive(crack, "", len, encryptedForDecrypted, hashType, attempts, totalAttempts);
    }

    cout << "Password not found within the given length range." << endl;
}
