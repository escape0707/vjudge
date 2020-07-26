#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;

int main() {
  while (cin) {
    int A, B, K;
    cin >> A >> B >> K;
    if (A == 0 && B == 0) {
      return 0;
    }
    if ((A - B) % static_cast<int>(pow(10, K)) == 0) {
      cout << -1 << endl;
    } else {
      cout << A + B << endl;
    }
  }
}
