while true; do
  ./gen.exe
  ./ac.exe < input.txt > answer.txt
  ./383077-I.exe < input.txt > output.txt
  diff -s answer.txt output.txt
  if [ $? -ne 0 ]; then
    break
  fi
done
