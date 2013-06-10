!include "MUI2.nsh"

Name "Qt5 Runtime Libraries"
OutFile "qt5rt.exe"

!define MUI_HEADERIMAGE
!define MUI_HEADERIMAGE_BITMAP

!insertmacro MUI_PAGE_LICENSE "license.txt"
!insertmacro MUI_PAGE_INSTFILES

!insertmacro MUI_UNPAGE_CONFIRM
!insertmacro MUI_UNPAGE_INSTFILES

Section "Qt5 Runtime Libraries"
	SetOutPath $SYSDIR
	File "C:\Qt\Qt5.0.2\5.0.2\mingw47_32\bin\D3DCompiler_43.dll"
	File "C:\Qt\Qt5.0.2\5.0.2\mingw47_32\bin\icudt49.dll"
	File "C:\Qt\Qt5.0.2\5.0.2\mingw47_32\bin\icuin49.dll"
	File "C:\Qt\Qt5.0.2\5.0.2\mingw47_32\bin\icuuc49.dll"
	File "C:\Qt\Qt5.0.2\5.0.2\mingw47_32\bin\libEGL.dll"
	File "C:\Qt\Qt5.0.2\5.0.2\mingw47_32\bin\libGLESv2.dll"
	File "C:\Qt\Qt5.0.2\5.0.2\mingw47_32\bin\libwinpthread-1.dll"
	File "C:\Qt\Qt5.0.2\5.0.2\mingw47_32\bin\Qt5Core.dll"
	File "C:\Qt\Qt5.0.2\5.0.2\mingw47_32\bin\Qt5Gui.dll"
	File "C:\Qt\Qt5.0.2\5.0.2\mingw47_32\bin\Qt5Script.dll"
	File "C:\Qt\Qt5.0.2\5.0.2\mingw47_32\bin\Qt5Widgets.dll"
	File "C:\Qt\Qt5.0.2\5.0.2\mingw47_32\bin\Qt5Xml.dll"
	WriteUninstaller "$SYSDIR\qt5-rt-uninstall.exe"
SectionEnd

Section "Uninstall"
	Delete "$SYSDIR\D3DCompiler_43.dll"
	Delete "$SYSDIR\icudt49.dll"
	Delete "$SYSDIR\icuin49.dll"
	Delete "$SYSDIR\icuuc49.dll"
	Delete "$SYSDIR\libEGL.dll"
	Delete "$SYSDIR\libGLESv2.dll"
	Delete "$SYSDIR\libwinpthread-1.dll"
	Delete "$SYSDIR\Qt5Core.dll"
	Delete "$SYSDIR\Qt5Gui.dll"
	Delete "$SYSDIR\Qt5Script.dll"
	Delete "$SYSDIR\Qt5Widgets.dll"
	Delete "$SYSDIR\Qt5Xml.dll"
	Delete "$SYSDIR\qt5-rt-uninstall.exe"
SectionEnd
