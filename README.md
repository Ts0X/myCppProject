# My C++ Project

This is a C++ project that includes various features like brute force, hash functions, AES encryption/decryption, and a keylogger.

#First clone the repository, run the installer, if the installer doesn't help read the readme and do it manually.

## Requirements

Before you can build and run the project, make sure you have the following installed:

- **MinGW**: A C++ compiler.
  - Download MinGW from [here](https://sourceforge.net/projects/mingw-w64/).
  - Ensure that MinGW's `bin` folder is added to your system's `PATH` environment variable, so you can run `g++` from the command line.
  
- **OpenSSL**: Required for cryptographic operations.
  - Download OpenSSL from [here](https://slproweb.com/products/Win32OpenSSL.html).
  - After installation, make sure the OpenSSL `bin` folder is also added to your system's `PATH` to allow the project to link with OpenSSL libraries.

- **Crypto++ Library**: Used for cryptographic functions.
  - Download Crypto++ from [here](https://www.cryptopp.com/).
  - Extract the Crypto++ files and make sure the `include` and `lib` folders are properly referenced when compiling the project.

## Setting up the Project

1. **Clone the repository**:
   Clone the repository to your local machine using Git:
   ```bash
   git clone https://github.com/Ts0X/myCppProject.git
   cd myCppProject
2. **Once the dependencies are in place, you can compile the project using MinGW. Open a terminal in the project directory and run the following command**:
  ```bash
    //use this if the installer cant create the main.exe!
     g++ main.cpp brute_force.cpp hash_Functions.cpp dictionary.cpp aes_encrypt.cpp aes_decrypt.cpp createHash.cpp keylogger.cpp passGen.cpp hashidentify.cpp aes_common.cpp -o main -I"C:\Program Files\OpenSSL-Win64\include" -L"C:\Program Files\OpenSSL-Win64\lib\VC\x64\MD" -lssl -lcrypto
      ./main.exe
``` 
