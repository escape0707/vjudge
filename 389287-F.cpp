#include <algorithm>
#include <array>
#include <iostream>
#include <vector>

using namespace std;

#define endl '\n'
static auto speedup = [] {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  return nullptr;
}();

static vector<bool> is_sqr(10001, false);
static vector<int> my_sqrt(10001, 0);

static void solve(int num) {
  for (int i = 1; i <= 100; ++i) {
    for (int j = i; j <= 100; ++j) {
      int num_sum = i * i + j * j;
      if (num_sum > num) {
        break;
      }
      if (is_sqr[num - num_sum]) {
        vector<int> tmp = {i, j, my_sqrt[num - num_sum]};
        sort(tmp.begin(), tmp.end());
        cout << tmp[0] << ' ' << tmp[1] << ' ' << tmp[2] << endl;
        return;
      }
    }
  }
}

int main() {
  for (int i = 1; i <= 100; ++i) {  // no 0, positive solution only
    is_sqr[i * i] = true;
    my_sqrt[i * i] = i;
  }
  int num;
  while (cin >> num) {
    solve(num);
  }
}
