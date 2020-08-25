#include <algorithm>
#include <cmath>
#include <iostream>

using namespace std;

#define endl '\n'
static auto speedup = [] {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  return nullptr;
}();

int main() {
  double V, D;
  while (cin >> V >> D) {
    int cnt = 1;
    int time = 0;
    int total = static_cast<int>(ceil(V / D));
    while (total > 0) {
      time += min(total, cnt);
      total -= cnt;
      ++cnt;
      if (total > 0) {
        time += 1;
      }
    }
    cout << time << endl;
  }
}
