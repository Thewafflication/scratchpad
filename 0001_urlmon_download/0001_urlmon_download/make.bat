@echo off
cl /nologo /W3 /Od /Zi main.c /Fe0001_urlmon_download.exe
if errorlevel 1 exit /b 1