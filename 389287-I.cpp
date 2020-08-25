#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

#define endl '\n'
static auto speedup = [] {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  return nullptr;
}();

int main() {
  string s1, s2;
  cin >> s1 >> s2;
  vector<vector<int>> dp(s1.size() + 1, vector<int>(s2.size() + 1));
  for (int i = 0; i <= s1.size(); ++i) {
    for (int j = 0; j <= s2.size(); ++j) {
      if (min(i, j) == 0) {
        dp[i][j] = max(i, j);
      } else {
        dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + 1;
        dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] +
                                     static_cast<int>(s1[i - 1] != s2[j - 1]));
      }
    }
  }
  cout << dp[s1.size()][s2.size()] << endl;
}
