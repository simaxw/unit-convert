!include "MUI2.nsh"

Name "Convert Unit Conversion Tool"
OutFile "convert.exe"
InstallDir "$PROGRAMFILES\convert"

!define MUI_HEADERIMAGE
!define MUI_HEADERIMAGE_BITMAP

!insertmacro MUI_PAGE_LICENSE "license.txt"
!insertmacro MUI_PAGE_DIRECTORY
!insertmacro MUI_PAGE_STARTMENU Convert $StartMenuFolder
!insertmacro MUI_PAGE_INSTFILES

!insertmacro MUI_UNPAGE_CONFIRM
!insertmacro MUI_UNPAGE_INSTFILES

Section "Convert Unit Conversion Tool"
	SetOutPath "$INSTDIR"
	File "..\bin\convert.exe"
	File "..\bin\data.rcc"
	File "..\bin\units.xml"
	WriteUninstaller "$INSTDIR\convert-uninstall.exe"

	!insertmacro MUI_STARTMENU_WRITE_BEGIN Convert
		
	!insertmacro MUI_STARTMENU_WRITE_END
SectionEnd

Section "Uninstall"
	Delete "$INSTDIR\convert.exe"
	Delete "$INSTDIR\data.rcc"
	Delete "$INSTDIR\units.xml"
	Delete "$INSTDIR\convert-uninstall.exe"
	RMDir "$INSTDIR"
SectionEnd
