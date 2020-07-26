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
    int curr, max_cnt = numeric_limits<int>::min();
    long long sum = 0;
    while (N--) {
      cin >> curr;
      max_cnt = max(curr, max_cnt);
      sum += curr;
    }
    cout << (max_cnt <= (sum + 1) / 2 ? "Yes" : "No") << endl;
  }
}
