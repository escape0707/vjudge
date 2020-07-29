@echo off
set problem=383077-E

g++ rand.cpp -o rand.exe
g++ std.cpp -o std.exe
g++ %problem%.cpp -o %problem%.exe

:loop
rand.exe > input.txt
std.exe < input.txt > answer.txt
%problem%.exe < input.txt > output.txt
fc answer.txt output.txt
if not errorlevel 1 goto loop
