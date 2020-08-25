#include <iostream>
#include <vector>

using namespace std;

#define endl '\n'
static auto speedup = [] {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  return nullptr;
}();

static constexpr int CHECK_RANGE = 10001;
static vector<int> prime_collection;
static vector<bool> is_prime(CHECK_RANGE + 1, true);

static void generate_primes() {
  is_prime[0] = is_prime[1] = false;
  for (int i = 2; i < CHECK_RANGE; ++i) {
    if (is_prime[i]) {
      prime_collection.push_back(i);
      for (int j = i + i; j < CHECK_RANGE; j += i) {
        is_prime[j] = false;
      }
    }
  }
}

int main() {
  generate_primes();
  int curr;
  while (cin >> curr) {
    for (int i = curr / 2; i > 1; --i) {
      if (is_prime[i] && is_prime[curr - i]) {
        cout << i << ' ' << curr - i << endl;
        break;
      }
    }
  }
}
