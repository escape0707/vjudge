# This script is currently not working.
# Besides that, for capatibility with Windows 7, please use verify.cmd
$problem = "383077-E"
g++ gen.cpp -o gen.exe
g++ ac.cpp -o ac.exe
g++ $problem.cpp -o $problem.exe
while ($true) {
  gen.exe
  cat input.txt | ac.exe > answer.txt
  cat input.txt | $problem.exe > output.txt
  if (diff (cat file1) (cat file2)) {
    break
  }
}
