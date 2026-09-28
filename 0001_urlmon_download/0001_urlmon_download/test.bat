@echo off

echo --- Test1: No args ---
echo.
0001_urlmon_download.exe
echo.
echo Error Level: %errorlevel%
echo.

echo --- Test2: URL Only ---
echo.
0001_urlmon_download.exe http://www.google.com/
echo.
echo Error Level: %errorlevel%
echo.

echo --- Test3: Bad URL ---
echo.
0001_urlmon_download.exe http://badurl/
echo.
echo Error Level: %errorlevel%
echo.

echo --- Test4: url and filename ---
echo.
0001_urlmon_download.exe https://jordan.waughtal.rocks/g/ index.html
echo.
echo Error Level: %errorlevel%
echo.

pause