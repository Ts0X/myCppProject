# My C++ Project

How it works:
In this code you can make a brute-force or dictionary attack in hashes. Be careful, you must know what type of hash they are.
You can use my Hash Identify that recognizes the hash based on its length. Also, you can encrypt your own hash. 
To use keylogger, you need to create a .txt file to hold the datas. Remember that the keylogger is used for your own PC.
You can encrypt with AES but you can not decrypt AES without all the keys! So it works only for your AES Encryption.
Also, the code can generate strong passwords.

## Setting up the Project

1. **Clone the repository**:
   Clone the repository to your local machine using Git:
   ```bash
   git clone https://github.com/Ts0X/myCppProject.git
   cd myCppProject

2. **MinGW**: A C++ compiler.
    - Download MinGW from [here](https://sourceforge.net/projects/mingw-w64/).
    - Ensure that MinGW's `bin` folder is added to your system's `PATH` environment variable, so you can run `g++` from the command line.

3.**OpenSSL**:
   - Download OpenSSL from [here](https://slproweb.com/products/Win32OpenSSL.html).
   - After installation, make sure the OpenSSL `bin` folder is also added to your system's `PATH` to allow the project to link with OpenSSL libraries.

4.**Crypto++ Library**:
   - Download Crypto++ from [here](https://sourceforge.net/projects/cryptopp/).
   - Extract the Crypto++ files and make sure the `include` and `lib` folders are properly referenced when compiling the project.


## Requirements

Before you can build and run the project, make sure you have the following installed:

- **MinGW**: A C++ compiler.
 
- **OpenSSL**: Required for cryptographic operations.

- **Crypto++ Library**: Used for cryptographic functions.
    
- **Library for Dictionary Attacks**:
  - You can use whatever library you want.
  - Download rockou.txt library[here](https://weakpass.com/wordlists/rockyou.txt).
    
- **Keylogger**:
  - To use keylogger you need to insert inside the keylogger.cpp -> const char* filePath = ""; your .txt file to hold the keys.
  
 #Once the dependencies are in place, you can compile the project using MinGW. Open a terminal in the project directory and run the following command**:
 - This command must create the main.exe.
  ```bash 
     g++ main.cpp brute_force.cpp hash_Functions.cpp dictionary.cpp aes_encrypt.cpp aes_decrypt.cpp createHash.cpp keylogger.cpp passGen.cpp hashidentify.cpp aes_common.cpp -o main -  I"C:\Program Files\OpenSSL-Win64\include" -L"C:\Program Files\OpenSSL-Win64\lib\VC\x64\MD" -lssl -lcrypto
  ```
 #Since main.exe has been created run this command:
``` 
 ./main
```
