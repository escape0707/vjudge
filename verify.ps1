$problem = "383077-E"
g++ gen.cpp -o gen.exe
g++ ac.cpp -o ac.exe
g++ $problem.cpp -o $problem.exe
while ($true) {
  gen.exe
  ac.exe < input.txt > answer.txt
  $problem.exe < input.txt > output.txt
  if (diff (cat file1) (cat file2)) {
    break
  }
}
