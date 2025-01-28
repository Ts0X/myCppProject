#include <iostream>
#include <openssl/aes.h>
#include <openssl/evp.h>
#include <openssl/rand.h>
#include "aes_encrypt.h"
#include "aes_common.h"


using namespace std;

void encrypt_text_aes() {

    string inputText;
    cout << "Enter the text for encryption: " << endl;
    getline(cin, inputText);

    if(inputText.empty()) {
        cout << "Can't generate with zero-length input" << endl;
        return;
    }

    unsigned char *plaintext = (unsigned char*)inputText.c_str();

    if(!RAND_bytes(key, sizeof(key)) || !RAND_bytes(iv, sizeof(iv))) {
        cerr << "Random key/IV generation failed" << endl;
        return;
    }

    unsigned char ciphertext[256];
    int ciphertext_len = encrypt(plaintext, inputText.size(), ciphertext);

    cout << "Ciphertext is: ";
    for(int i = 0; i < ciphertext_len; i++) {
        printf("%02x", ciphertext[i]);
    }
    cout << endl;

    cout << "Key (in hex): ";
    for (int i = 0; i < sizeof(key); i++) {
        printf("%02x", key[i]);
    }
    cout << endl;

    cout << "IV (in hex): ";
    for (int i = 0; i < sizeof(iv); i++) {
        printf("%02x", iv[i]);
    }
    cout << endl;
}
