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
; All project files
Source: "*.cpp"; DestDir: "{app}"; Flags: ignoreversion
Source: "*.h"; DestDir: "{app}"; Flags: ignoreversion
Source: "key_file.txt"; DestDir: "{app}"; Flags: ignoreversion

; Crypto++ Library (assuming the contents are in the `libs` folder)
Source: "libs\*"; DestDir: "{app}\libs"; Flags: recursesubdirs createallsubdirs

[Run]
; Add MinGW to PATH (assuming the user has already downloaded MinGW)
Filename: "{cmd}"; Parameters: "/C setx PATH ""{app}\mingw\bin;%PATH%"""; Flags: runhidden

; Compile and create the executable
Filename: "{cmd}"; Parameters: "/C g++ main.cpp brute_force.cpp hash_Functions.cpp dictionary.cpp aes_encrypt.cpp aes_decrypt.cpp createHash.cpp keylogger.cpp passGen.cpp hashidentify.cpp aes_common.cpp -o main -I""C:\Program Files\OpenSSL-Win64\include"" -L""C:\Program Files\OpenSSL-Win64\lib\VC\x64\MD"" -lssl -lcrypto"; WorkingDir: "{app}"; Flags: runhidden

; Run the program after installation
Filename: "{app}\main.exe"; Flags: nowait postinstall skipifsilent
