@echo off
echo Compiling...
gcc main.c -o main.exe -I"C:\Users\HP\Downloads\SDL3-devel-3.4.2-mingw\SDL3-3.4.2\i686-w64-mingw32\include" -L"C:\Users\HP\Downloads\SDL3-devel-3.4.2-mingw\SDL3-3.4.2\i686-w64-mingw32\lib" -lSDL3

if %errorlevel% neq 0 (
    echo.
    echo BUILD FAILED! Fix the errors above.
    pause
    exit /b
)

echo Success! Running program...
.\main.exe