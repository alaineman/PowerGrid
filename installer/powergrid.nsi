; Basic Installer settings
!define VERSION 0.1
Name "PowerGrid v${VERSION}"
OutFile "PowerGrid v${VERSION} Setup.exe"
InstallDir $PROGRAMFILES\PowerGrid
Icon "..\src\images\setup.ico"
InstallColors /windows

InstallDirRegKey HKLM "Software\PowerGrid" "Install_Dir"

RequestExecutionLevel admin

; Compression settings
SetCompressor /SOLID lzma
SetCompressorDictSize 4

;--------------------------------

; Pages

Page license
Page directory
Page instfiles

UninstPage uninstConfirm
UninstPage instfiles

;--------------------------------

; License info
LicenseData license.txt
LicenseForceSelection off
LicenseBKColor /windows

ShowInstDetails nevershow
ShowUninstDetails nevershow

VIProductVersion                "${VERSION}.0.0"
VIAddVersionKey ProductName     "PowerGrid"
VIAddVersionKey ProductVersion  "${VERSION}"
VIAddVersionKey FileVersion     "${VERSION}"
VIAddVersionKey FileDescription "Bot client for the MMORPG Runescape"
VIAddVersionKey LegalCopyright  "it is licensed under GPL"

; Set the install section itself
; This is mainly PowerGrid and any DLL files in the installer directory.
; Any jar files are also included.
; Uninstall info is also included. 
Section "PowerGrid"

    SectionIn RO

    SetOutPath $INSTDIR
    File PowerGrid.exe
    File *.dll
    File *.jar
    File license.txt

    WriteRegStr HKLM SOFTWARE\PowerGrid "Install_Dir" "$INSTDIR"

    ; Write the uninstall keys for Windows into the registry
    WriteRegStr HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\PowerGrid" "DisplayName" "PowerGrid"
    WriteRegStr HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\PowerGrid" "UninstallString" '"$INSTDIR\uninstall.exe"'
    WriteRegDWORD HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\PowerGrid" "NoModify" 1
    WriteRegDWORD HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\PowerGrid" "NoRepair" 1
    WriteUninstaller "uninstall.exe"

SectionEnd

; Optional section (can be disabled by the user)
Section "Start Menu Shortcuts"

  CreateDirectory "$SMPROGRAMS\PowerGrid"
  CreateShortCut "$SMPROGRAMS\PowerGrid\Uninstall.lnk" "$INSTDIR\uninstall.exe" "" "$INSTDIR\uninstall.exe" 0
  CreateShortCut "$SMPROGRAMS\PowerGrid\PowerGrid.lnk" "$INSTDIR\PowerGrid.exe" "" "$INSTDIR\PowerGrid.exe" 0
  
SectionEnd

;--------------------------------

; Uninstaller

Section "Uninstall"
  
  ; Remove registry keys
  DeleteRegKey HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\PowerGrid"
  DeleteRegKey HKLM SOFTWARE\PowerGrid

  ; Remove contents of installation directory
  Delete $INSTDIR\*.*

  ; Remove shortcuts, if any
  Delete "$SMPROGRAMS\PowerGrid\*.*"

  ; Remove directories used
  RMDir "$SMPROGRAMS\PowerGrid"
  RMDir "$INSTDIR"

SectionEnd