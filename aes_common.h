#ifndef AES_COMMON_H
#define AES_COMMON_H

#include <openssl/aes.h>
#include <openssl/evp.h>
#include <openssl/err.h>

extern unsigned char key[32];  // Global key variable
extern unsigned char iv[16];   // Global IV variable

void handleErrors();
int encrypt(unsigned char *plaintext, int plaintext_len, unsigned char *ciphertext);
int decrypt(unsigned char *ciphertext, int ciphertext_len, unsigned char *plaintext);

#endif // AES_COMMON_H
