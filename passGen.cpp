#include<iostream>
#include<cstdlib>
#include"passGen.h"
using namespace std;
void pass_gen() {
    static const char alphanum[] =
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz"
        "!@#$%^&*()_+=-?/>.<,~`:;'"
        "1234567890";

    int size = sizeof(alphanum) - 1;
    int ammountOfChar;

    cout << "Enter amount of characters: " << endl;
    cin >> ammountOfChar;

    if(ammountOfChar <= 0) {
        cout << "Can't generate with 0" << endl;
        return;
    }

    srand(time(0));
    for(int i = 0; i < ammountOfChar; ++i) {
        cout << alphanum[rand() % size];
    }
    cout << endl;
}