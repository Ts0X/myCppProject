#include <iostream>
#include <limits>
#include "brute_force.h"
#include "dictionary.h"
#include "hashidentify.h"
#include "createHash.h"
#include "passGen.h"
#include "aes_encrypt.h"
#include "aes_decrypt.h"
#include "keylogger.h"

using namespace std;

int main () {
    // Program started. User options.
    system("cls");
    std::cout << R"(
  _______     _____      __   __  
 |__   __|   / ____|     \ \ / /  
    | |     | (___        \ V /   
    | |      \___ \   O    > <    
    | |      ____) |     / / . \   
    |_|     |_____/     /_/   \_\  
    No Copyright © 2024. All Rights Reserved.
  This tool is for educational purposes only.
  Use responsibly and at your own risk.
    )" << std::endl << endl <<endl;
    system("Color 0B");
    
    int choice;
    char exitChoice;
    
    do {
        // Display menu options
        cout << "1. Brute-Force Attack" << endl;
        cout << "2. Dictionary Attack" << endl;
        cout << "3. Hash Identify" << endl;
        cout << "4. Encrypt Hash" << endl;
        cout << "5. Encrypt With AES" << endl;
        cout << "6. Decrypt With AES (all keys needed)" << endl;
        cout << "7. KeyLogger" << endl;
        cout << "8. Password Generator" << endl;
        cout << "Select an option (1-8): ";
        
        // Check if the input is a valid integer
        while (!(cin >> choice) || choice < 1 || choice > 8) {
            cout << "Invalid choice. Please select an option between 1-8: ";
            cin.clear();  
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Ignore any invalid input
        }
        
        cin.ignore();  // Clear the newline character from the input buffer

        switch (choice) {
            case 1:
                BruteForce(); // call the BruteForce function
                break;
            case 2:
                Dictionary(); // call dictionary attack function
                break;
            case 3:
                identify(); // call hash identifier
                break;
            case 4:
                createHash(); // call hash creator
                break;
            case 5:
                encrypt_text_aes(); // call encrypt with aes
                break;
            case 6:
                decrypt_text_aes(); // call decrypt with aes
                break;
            case 7:
                keylogger(); // call keylogger
                break;
            case 8:
                pass_gen(); // call password generator
                break;
        }

        // Ask the user if they want to exit or continue
        cout << "Press 'e' to exit, or any other key to return to the main menu: ";
        cin >> exitChoice;
        
    } while (exitChoice != 'e');

    return 0;
}
