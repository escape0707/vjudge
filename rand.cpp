#include <array>
#include <iostream>
#include <random>
#include <vector>
using namespace std;

static int random_int(int a, int b) {
  static random_device rd;
  static default_random_engine e(rd());
  uniform_int_distribution<> u(a, b);
  return u(e);
}

static void print_random_Mars_number() {
  static constexpr array<int, 25> prime_collection = {
      2,  3,  5,  7,  11, 13, 17, 19, 23, 29, 31, 37, 41,
      43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};

  int length = random_int(1, 25);
  cout << random_int(length == 1 ? 0 : 1, prime_collection[length - 1] - 1);
  while (--length) {
    cout << ',' << random_int(0, prime_collection[length - 1] - 1);
  }
}

int main() {
  int CASE_CNT = 100;
  while (CASE_CNT--) {
    print_random_Mars_number();
    cout << ' ';
    print_random_Mars_number();
    cout << endl;
  }
  cout << "0 0" << endl;
}
