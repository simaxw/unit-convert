@echo off

REM Needs the Qt Installer Framework installed in c:\qtinstfw

c:\qtinstfw\bin\binarycreator.exe --offline-only -c config\config.xml -p packages setup.exe 
