# This script is currently not working.
# Besides that, for compatibility with Windows 7, please use verify.cmd
$problem = "383077-E"
g++ rand.cpp -o rand.exe
g++ std.cpp -o std.exe
g++ "$problem.cpp" -o "$problem.exe"
while ($true) {
  .\rand.exe
  cat input.txt | .\std.exe > answer.txt
  cat input.txt | ".\$($problem).exe" > output.txt
  if (diff (cat file1) (cat file2)) {
    break
  }
}
