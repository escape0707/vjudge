problem=383077-E
g++ rand.cpp -o rand.out
g++ std.cpp -o std.out
g++ $problem.cpp -o $problem.out
while true; do
  ./rand.out
  ./std.out < input.txt > answer.txt
  ./$problem.out < input.txt > output.txt
  diff -s answer.txt output.txt
  if [ $? -ne 0 ]; then
    break
  fi
done
