#include <math.h>
#include <stdio.h>
#include <string.h>

#include <stack>
using namespace std;
int main() {
  char num1[1000];
  char num2[1000];
  int prim[26] = {0,  2,  3,  5,  7,  11, 13, 17, 19, 23, 29, 31, 37,
                  41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
  while (~scanf("%s %s", num1, num2)) {
    if (strcmp(num1, "0") == 0 && strcmp(num2, "0") == 0) break;
    int len1 = strlen(num1);
    int len2 = strlen(num2);
    int t1 = len1 - 1, t2 = len2 - 1;
    stack<int> s;
    int r = 0;
    int cnt = 1;
    while (t1 >= 0 || t2 >= 0) {
      int mul = 0;
      int a = 0, b = 0;
      for (; t1 >= 0; t1--) {
        if (num1[t1] >= '0' && num1[t1] <= '9')
          a = a + (num1[t1] - '0') * pow(10, mul++);
        else
          break;
      }
      mul = 0;
      for (; t2 >= 0; t2--) {
        if (num2[t2] >= '0' && num2[t2] <= '9')
          b = b + (num2[t2] - '0') * pow(10, mul++);
        else
          break;
      }

      //  printf("r=%d \n",a+b+r);
      s.push((a + b + r) % prim[cnt]);
      r = (a + b + r) / prim[cnt];
      t1--, t2--, cnt++;
    }
    if (r) s.push(r);
    printf("%d", s.top());
    s.pop();
    while (!s.empty()) printf(",%d", s.top()), s.pop();
    printf("\n");
  }
}
