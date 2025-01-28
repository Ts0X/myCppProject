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
; MinGW Compiler
Source: "MinGW\*"; DestDir: "{app}\MinGW"; Flags: recursesubdirs createallsubdirs

; OpenSSL
Source: "win32openssl.msi"; DestDir: "{app}\OpenSSL"; Flags: ignoreversion

; Crypto++ Library
Source: "cryptopp564.zip"; DestDir: "{app}\Crypto++"; Flags: ignoreversion

; Project files (C++ and headers)
Source: "*.cpp"; DestDir: "{app}"; Flags: ignoreversion
Source: "*.h"; DestDir: "{app}"; Flags: ignoreversion
Source: "key_file.txt"; DestDir: "{app}"; Flags: ignoreversion

[Run]
; Install OpenSSL
Filename: "{app}\OpenSSL\Win32OpenSSL-3_3_2.msi"; Parameters: "/quiet"; Flags: runhidden waituntilterminated

; Unzip Crypto++ Library
Filename: "{cmd}"; Parameters: "/C powershell -Command Expand-Archive '{app}\Crypto++\cryptopp564.zip' -DestinationPath '{app}\libs'"; Flags: runhidden waituntilterminated

; Add MinGW to PATH
Filename: "{cmd}"; Parameters: "/C setx PATH ""{app}\MinGW\bin;%PATH%"""; Flags: runhidden

; Compile and create the executable
Filename: "{cmd}"; Parameters: "/C g++ {app}\*.cpp -o {app}\main.exe -I""{app}\OpenSSL\include"" -L""{app}\OpenSSL\lib"" -lssl -lcrypto"; WorkingDir: "{app}"; Flags: runhidden

; Run the program after installation
Filename: "{app}\main.exe"; Flags: nowait postinstall skipifsilent
