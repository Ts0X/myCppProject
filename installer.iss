; -----------------------------------------
; Setup Script for My C++ Project
; -----------------------------------------

[Setup]
AppName=My C++ Project
AppVersion=1.0
DefaultDirName={pf}\MyCppProject
DefaultGroupName=My C++ Project
OutputDir=.
OutputBaseFilename=MyCppProjectInstaller
Compression=lzma
SolidCompression=yes
DisableDirPage=yes
DisableProgramGroupPage=yes

[Files]
; Project source files
Source: "*.cpp"; DestDir: "{app}"; Flags: ignoreversion
Source: "*.h"; DestDir: "{app}"; Flags: ignoreversion

; Include the zipped libraries (MinGW, OpenSSL, Crypto++)
Source: "mingw-w64-v11.0.0.zip"; DestDir: "{tmp}"; Flags: deleteafterinstall
Source: "cryptopp564.zip"; DestDir: "{tmp}"; Flags: deleteafterinstall
Source: "Win32OpenSSL-3_3_2.msi"; DestDir: "{tmp}"; Flags: deleteafterinstall

[Run]
; 7z.exe is used to extract the MinGW, OpenSSL, and Crypto++ files
Filename: "{app}\7z.exe"; Parameters: "x {tmp}\mingw-w64-v11.0.0.zip -o{app}\MinGW\"; Flags: runhidden waituntilterminated
Filename: "{app}\7z.exe"; Parameters: "x {tmp}\cryptopp564.zip -o{app}\Crypto++\"; Flags: runhidden waituntilterminated

; Install OpenSSL silently
Filename: "{tmp}\Win32OpenSSL-3_3_2.msi"; Parameters: "/quiet"; Flags: runhidden waituntilterminated

; Add MinGW to PATH
Filename: "{cmd}"; Parameters: "/C setx PATH ""{app}\MinGW\bin;%PATH%"""; Flags: runhidden

; Compile and create the executable (main.exe) using g++
Filename: "{cmd}"; Parameters: "/C g++ {app}\main.cpp {app}\brute_force.cpp {app}\hash_Functions.cpp {app}\dictionary.cpp {app}\aes_encrypt.cpp {app}\aes_decrypt.cpp {app}\createHash.cpp {app}\keylogger.cpp {app}\passGen.cpp {app}\hashidentify.cpp {app}\aes_common.cpp -o {app}\main.exe -I""{app}\Crypto++\include"" -L""{app}\Crypto++\lib"" -lssl -lcrypto"; Flags: runhidden waituntilterminated

; Clean up the temporary files after installation
Filename: "{cmd}"; Parameters: "/C del {tmp}\mingw-w64-v11.0.0.zip"; Flags: runhidden
Filename: "{cmd}"; Parameters: "/C del {tmp}\cryptopp564.zip"; Flags: runhidden
Filename: "{cmd}"; Parameters: "/C del {tmp}\Win32OpenSSL-3_3_2.msi"; Flags: runhidden

; Run the program after installation
Filename: "{app}\main.exe"; Flags: nowait postinstall skipifsilent
