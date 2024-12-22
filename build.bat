@echo off

::gcc -Wall -Wextra -std=c2x -pedantic taikore34.c -o bin\taikore34.exe
::if %errorlevel% neq 0 goto end
::.\bin\taikore34.exe

gcc -Wall -Wextra -std=c2x -pedantic code\cubemain.c code\cubefunc.c -o bin\cubemain.exe
if %errorlevel% neq 0 goto end
.\bin\cubemain.exe

:end