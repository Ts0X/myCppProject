#include "hash_Functions.h"
#include <openssl/md5.h>
#include <openssl/sha.h>
#include <iomanip>
#include <sstream>

std::string md5(const std::string& input) {
    unsigned char digest[MD5_DIGEST_LENGTH];
    MD5(reinterpret_cast<const unsigned char*>(input.c_str()), input.size(), digest);

    std::ostringstream oss;
    for(int i = 0; i < MD5_DIGEST_LENGTH; ++i) {
        oss << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(digest[i]);
    }
    return oss.str();
}

std::string sha1(const std::string& input) {
    unsigned char digest[SHA_DIGEST_LENGTH];
    SHA1(reinterpret_cast<const unsigned char*>(input.c_str()), input.size(), digest);

    std::ostringstream oss;
    for(int i = 0; i < SHA_DIGEST_LENGTH; ++i) {
        oss << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(digest[i]);
    }
    return oss.str();
}

std::string sha224(const std::string& input) {
    unsigned char digest[SHA224_DIGEST_LENGTH];
    SHA224(reinterpret_cast<const unsigned char*>(input.c_str()), input.size(), digest);

    std::ostringstream oss;
    for(int i = 0; i < SHA224_DIGEST_LENGTH; ++i) {
        oss << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(digest[i]);
    }
    return oss.str();
}

std::string sha256(const std::string& input) {
    unsigned char digest[SHA256_DIGEST_LENGTH];
    SHA256(reinterpret_cast<const unsigned char*>(input.c_str()), input.size(), digest);

    std::ostringstream oss;
    for(int i = 0; i < SHA256_DIGEST_LENGTH; ++i) {
        oss << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(digest[i]);
    }
    return oss.str();
}

std::string sha384(const std::string& input) {
    unsigned char digest[SHA384_DIGEST_LENGTH];
    SHA384(reinterpret_cast<const unsigned char*>(input.c_str()), input.size(), digest);

    std::ostringstream oss;
    for(int i = 0; i < SHA384_DIGEST_LENGTH; ++i) {
        oss << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(digest[i]);
    }
    return oss.str();
}

std::string sha512(const std::string& input) {
    unsigned char digest[SHA512_DIGEST_LENGTH];
    SHA512(reinterpret_cast<const unsigned char*>(input.c_str()), input.size(), digest);

    std::ostringstream oss;
    for(int i = 0; i < SHA512_DIGEST_LENGTH; ++i) {
        oss << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(digest[i]);
    }
    return oss.str();
}
