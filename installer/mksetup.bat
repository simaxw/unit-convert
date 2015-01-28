@echo off

REM Create Convert Installation Set
REM with the Qt Installation Framework
REM 2015-01-30 Simon Wilper (sxw@chronowerks.de)

FOR /F "delims=" %%i IN ( 'powershell -NoLogo -Command "(get-content ..\inc\main.hpp | select-string 'CONVERT_VERSION').line.split(' ')[2].Replace('""','')"' ) DO (set APPVERSION=%%i)
FOR /F "delims=" %%i IN ( 'powershell -NoLogo -Command "(get-content ..\inc\main.hpp | select-string 'CONVERT_DATE').line.split(' ')[2].Replace('""','')"' ) DO (set APPDATE=%%i)

echo.
echo Convert Setup Utility
echo =====================
echo Creating installer for Convert
echo.
echo o Version=%APPVERSION%
echo o Date=%APPDATE%

REM adjust paths and filelist as needed
set creator_exe=c:\qtinstfw\bin\binarycreator.exe

set qtsource=C:\Qt\5.4\mingw491_32
set qtflist=libgcc_s_dw2-1.dll libstdc++-6.dll libwinpthread-1.dll Qt5Core.dll Qt5Gui.dll Qt5Script.dll Qt5Widgets.dll Qt5Xml.dll icudt53.dll icuin53.dll icuuc53.dll

set appsource=..\release\bin
set appflist=convert.exe data.rcc

set pkgdir=packages\convert\data

REM ===================================

echo o Creating Directories
IF NOT EXIST %pkgdir% ( mkdir %pkgdir% )
IF NOT EXIST %pkgdir%\platforms ( mkdir %pkgdir%\platforms )

echo o Copying Qt Libraries
copy %qtsource%\plugins\platforms\qwindows.dll %pkgdir%\platforms

FOR %%f IN (%qtflist%) DO (
  copy "%qtsource%\bin\%%f" %pkgdir%
)

echo o Copying Application Files
FOR %%f IN (%appflist%) DO (
  copy %appsource%\%%f %pkgdir%
)

powershell -NoLogo -Command "(Get-Content packages\convert\meta\package.in.txt) | ForEach-Object { $_ -replace '{VERSION}', '%APPVERSION%' -replace '{DATE}', '%APPDATE%' } | Set-Content packages\convert\meta\package.xml"
powershell -NoLogo -Command "(Get-Content config\config.in.txt) | ForEach-Object { $_ -replace '{VERSION}', '%APPVERSION%' } | Set-Content config\config.xml"

set exename=convert-setup-%APPVERSION%.exe
echo o Building %exename%
%creator_exe% -v --offline-only -c config\config.xml -p packages %exename% 
