#include <iostream>
#include <openssl/aes.h>
#include <openssl/evp.h>
#include "aes_decrypt.h"
#include "aes_common.h"

using namespace std;



void decrypt_text_aes() {
    string inputText;
    cout << "Enter the ciphertext to decrypt (in hex format): " << endl;
    getline(cin, inputText);

    unsigned char ciphertext[256];
    int ciphertext_len = inputText.length() / 2;

    for(int i = 0; i < ciphertext_len; i++) {
        sscanf(&inputText[i * 2], "%2hhx", &ciphertext[i]);
    }

    string key_hex, iv_hex;
    cout << "Enter the key (in hex format): " << endl;
    getline(cin, key_hex);
    cout << "Enter the IV (in hex format): " << endl;
    getline(cin, iv_hex);

    for(int i = 0; i < sizeof(key); i++) {
        sscanf(&key_hex[i * 2], "%2hhx", &key[i]);
    }
    for(int i = 0; i < sizeof(iv); i++) {
        sscanf(&iv_hex[i * 2], "%2hhx", &iv[i]);
    }

    unsigned char decryptedtext[256];
    int decryptedtext_len = decrypt(ciphertext, ciphertext_len, decryptedtext);

    decryptedtext[decryptedtext_len] = '\0';
    cout << "Decrypted text is: " << decryptedtext << endl;
}
