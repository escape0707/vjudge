#include <algorithm>
#include <iostream>
#include <limits>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int T;
  cin >> T;
  while (T--) {
    int N;
    cin >> N;
    int max_cnt = numeric_limits<int>::min();
    long long sum = 0;
    while (N--) {
      int curr;
      cin >> curr;
      max_cnt = max(curr, max_cnt);
      sum += curr;
    }
    cout << (2 * max_cnt <= sum + 1 ? "Yes" : "No") << endl;
  }
}
