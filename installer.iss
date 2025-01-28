[Setup]
AppName=My C++ Project
AppVersion=1.0
DefaultDirName={pf}\MyCppProject
DefaultGroupName=My C++ Project
OutputDir=.
OutputBaseFilename=MyCppProjectInstaller
Compression=lzma
SolidCompression=yes

[Files]
; Όλα τα αρχεία του έργου
Source: "*.cpp"; DestDir: "{app}"; Flags: ignoreversion
Source: "*.h"; DestDir: "{app}"; Flags: ignoreversion
Source: "rockyou.txt"; DestDir: "{app}"; Flags: ignoreversion
Source: "key_file.txt"; DestDir: "{app}"; Flags: ignoreversion

; Προσθέτουμε το 7z.exe για αποσυμπίεση των zip αρχείων
Source: "path\to\7z.exe"; DestDir: "{app}"; Flags: ignoreversion

; Λειτουργίες αποσυμπίεσης των zip αρχείων
Source: "mingw-w64-v11.0.0.zip"; DestDir: "{tmp}"; Flags: ignoreversion
Source: "cryptopp564.zip"; DestDir: "{tmp}"; Flags: ignoreversion
Source: "Win32OpenSSL-3_3_2.msi"; DestDir: "{tmp}"; Flags: ignoreversion

; MinGW και Crypto++ Libraries
Source: "libs\*"; DestDir: "{app}\libs"; Flags: recursesubdirs createallsubdirs

[Run]
; Εκτελεί το 7z.exe για αποσυμπίεση των zip αρχείων
Filename: "{app}\7z.exe"; Parameters: "x ""{tmp}\mingw-w64-v11.0.0.zip"" -o""{app}\MinGW"" -y"; Flags: runhidden waituntilterminated
Filename: "{app}\7z.exe"; Parameters: "x ""{tmp}\cryptopp564.zip"" -o""{app}\CryptoPP"" -y"; Flags: runhidden waituntilterminated

; Εγκατάσταση του Win32OpenSSL από το MSI
Filename: "{tmp}\Win32OpenSSL-3_3_2.msi"; Parameters: "/quiet"; Flags: runhidden waituntilterminated

; Εκτελεί το MinGW-w64 για εγκατάσταση του MinGW
Filename: "{app}\MinGW\bin\mingw32-make.exe"; Parameters: "install"; WorkingDir: "{app}\MinGW"; Flags: runhidden waituntilterminated

; Δημιουργεί το executable χρησιμοποιώντας το g++
Filename: "{cmd}"; Parameters: "/C g++ main.cpp brute_force.cpp hash_Functions.cpp dictionary.cpp aes_encrypt.cpp aes_decrypt.cpp createHash.cpp keylogger.cpp passGen.cpp hashidentify.cpp aes_common.cpp -o main -I""{app}\OpenSSL\include"" -L""{app}\OpenSSL\lib"" -lssl -lcrypto"; WorkingDir: "{app}"; Flags: runhidden waituntilterminated

; Εκκινεί το main.exe
Filename: "{app}\main.exe"; Flags: nowait postinstall skipifsilent
