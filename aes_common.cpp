#include <openssl/evp.h>
#include <openssl/aes.h>
#include <openssl/err.h>
#include <iostream>
#include "aes_common.h"
#include <openssl/rand.h>

using namespace std;

unsigned char key[32];  // Define global key variable
unsigned char iv[16];   // Define global IV variable

void handleErrors() {
    ERR_print_errors_fp(stderr);
    abort();
}

// AES-256-CBC encryption function
int encrypt(unsigned char *plaintext, int plaintext_len, unsigned char *ciphertext) {
    EVP_CIPHER_CTX *ctx;
    int len;
    int ciphertext_len;

    // Create and initialize the context
    if (!(ctx = EVP_CIPHER_CTX_new())) handleErrors();

    // Initialize the encryption operation with AES-256-CBC
    if (1 != EVP_EncryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv))
        handleErrors();

    // Provide the message to be encrypted, and receive encrypted output
    if (1 != EVP_EncryptUpdate(ctx, ciphertext, &len, plaintext, plaintext_len))
        handleErrors();
    ciphertext_len = len;

    // Finalize the encryption
    if (1 != EVP_EncryptFinal_ex(ctx, ciphertext + len, &len)) handleErrors();
    ciphertext_len += len;

    // Clean up
    EVP_CIPHER_CTX_free(ctx);

    return ciphertext_len;
}

// AES-256-CBC decryption function
int decrypt(unsigned char *ciphertext, int ciphertext_len, unsigned char *plaintext) {
    EVP_CIPHER_CTX *ctx;
    int len;
    int plaintext_len;

    // Create and initialize the context
    if (!(ctx = EVP_CIPHER_CTX_new())) handleErrors();

    // Initialize the decryption operation with AES-256-CBC
    if (1 != EVP_DecryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv))
        handleErrors();

    // Provide the ciphertext to be decrypted, and receive decrypted output
    if (1 != EVP_DecryptUpdate(ctx, plaintext, &len, ciphertext, ciphertext_len))
        handleErrors();
    plaintext_len = len;

    // Finalize the decryption
    if (1 != EVP_DecryptFinal_ex(ctx, plaintext + len, &len)) handleErrors();
    plaintext_len += len;

    // Clean up
    EVP_CIPHER_CTX_free(ctx);

    return plaintext_len;
}

