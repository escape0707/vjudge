problem=383077-E
g++ gen.cpp -o gen.exe
g++ ac.cpp -o ac.exe
g++ $problem.cpp -o $problem.exe
while true; do
  ./gen.exe
  ./ac.exe < input.txt > answer.txt
  ./$problem.exe < input.txt > output.txt
  diff -s answer.txt output.txt
  if [ $? -ne 0 ]; then
    break
  fi
done
