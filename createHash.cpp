#include <iostream>
#include <string>
#include <algorithm>
#include "createHash.h"
#include "hash_Functions.h" 

using namespace std;
void createHash() {
    int EnType = 0;
        //Hash type choice
            do {
                cout << "  Choose Hash Type: "<< endl;
                cout <<"\t1. MD5 "<<endl;
                cout <<"\t2. SHA-1"<<endl;
                cout <<"\t3. SHA-224"<<endl;
                cout <<"\t4. SHA-256"<<endl;
                cout <<"\t5. SHA-384"<<endl;
                cout <<"\t6. SHA-512"<<endl;
                cin >> EnType;
                cin.ignore(); 
            } while (EnType < 1 || EnType > 6);

            switch (EnType) {
                case 1: {
                string inputText;
                cout << "Enter the text: " << endl;
                getline(cin, inputText);
                cout << "MD5 hash: " << md5(inputText) << endl;
                } break;
                //
                case 2: {
                string inputText;
                cout << "Enter the text: " << endl;
                getline(cin, inputText);
                cout << "SHA-1 hash: " << sha1(inputText) << endl;
                } break;
                //
                case 3 : {
                string inputText;
                cout <<"Enter the text: "<<endl;
                getline(cin,inputText);
                cout <<"sha-224 hash: "<<sha224(inputText)<<endl;
                }break;
                //
                case 4: {
                string inputText;
                cout <<"Enter the text: "<<endl;
                getline(cin,inputText);
                cout <<"sha-256 hash:"<<sha256(inputText)<<endl;
                }break;
                //
                case 5: {
                string inputText;
                cout << "Enter the text:"<<endl;
                getline(cin,inputText);
                cout << "sha-384 hash: "<<sha384(inputText)<<endl;
                }break;
                //
                case 6 :{
                string inputText;
                cout <<" Enter the text: "<<endl;
                getline(cin,inputText);
                cout << "sha512 hash: "<<sha512(inputText)<<endl;
                }break;
                default:
                cout << "Invalid choice!" << endl;
                    break;
            }
        
    
}