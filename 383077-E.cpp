#include <algorithm>
#include <array>
#include <iostream>
#include <iterator>
#include <utility>
#include <vector>

using namespace std;

static vector<int> generate_primes() {
  constexpr int N = 10000;
  array<bool, N> is_prime;
  vector<int> prime_collection;
  is_prime.fill(true);
  // is_prime[0] = is_prime[1] = false;
  for (int i = 2; i < N; ++i) {
    if (is_prime[i]) {
      prime_collection.push_back(i);
      for (int j = i + i; j < N; j += i) {
        is_prime[j] = false;
      }
    }
  }
  return prime_collection;
}

static vector<int> read_Mars_number() {
  vector<int> Mars_number;
  do {
    int digit;
    cin >> digit;
    Mars_number.push_back(digit);
  } while (cin.get() == ',');
  return Mars_number;
}

static vector<int> add_Mars_number_output_reversed(const vector<int> &A,
                                                   const vector<int> &B) {
  // const vector<int> prime_collection = generate_primes();
  // cout << '{';
  // copy(begin(prime_collection), begin(prime_collection) + 25,
  //      ostream_iterator<int>(cout, ", "));
  // cout << '}';
  static constexpr array<int, 25> prime_collection = {
      2,  3,  5,  7,  11, 13, 17, 19, 23, 29, 31, 37, 41,
      43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};

  vector<int> sum_reversed = {0};
  for (auto A_iter = A.crbegin(), A_end = A.crend(), B_iter = B.crbegin(),
            B_end = B.crend();
       A_iter != A_end || B_iter != B_end;) {
    int digit_A = 0, digit_B = 0;
    if (A_iter != A_end) {
      digit_A = *A_iter;
      ++A_iter;
    }
    if (B_iter != B_end) {
      digit_B = *B_iter;
      ++B_iter;
    }
    int &highest = sum_reversed.back();
    highest += digit_A + digit_B;
    const int base = prime_collection[sum_reversed.size() - 1];
    if (highest >= base) {
      highest -= base;
      sum_reversed.push_back(1);
    } else {
      sum_reversed.push_back(0);
    }
  }
  if (sum_reversed.back() == 0) {
    sum_reversed.pop_back();
  }
  return sum_reversed;
}

static void print_Mars_number_reversed(const vector<int> &Mars_number) {
  cout << Mars_number.back();
  for (auto iter = Mars_number.crbegin() + 1, e = Mars_number.crend();
       iter != e; ++iter) {
    cout << ',' << *iter;
  }
}

int main() {
  while (cin) {
    const vector<int> A = read_Mars_number(), B = read_Mars_number();
    if (A[0] == 0 && B[0] == 0) {
      break;
    }
    vector<int> &&sum_reversed = add_Mars_number_output_reversed(A, B);
    print_Mars_number_reversed(std::move(sum_reversed));
    cout << endl;
  }
}
