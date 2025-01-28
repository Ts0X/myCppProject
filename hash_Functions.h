#ifndef HASH_FUNCTIONS_H
#define HASH_FUNCTIONS_H

#include <string>

std::string md5(const std::string& input);
std::string sha1(const std::string& input);
std::string sha224(const std::string& input);
std::string sha256(const std::string& input);
std::string sha384(const std::string& input);
std::string sha512(const std::string& input);

#endif // HASH_FUNCTIONS_H
