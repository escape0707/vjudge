#include <array>
#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

#define endl '\n'
static auto speedup = [] {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  return nullptr;
}();

static constexpr array<int, 2> round = {2, 3};

int main() {
  int N;
  cin >> N;
  while (N--) {
    array<vector<int>, 2> id;
    int cnt;
    cin >> cnt;
    if (cnt == 0) {
      cout << endl;
      continue;
    }
    for (int i = 1; i <= cnt; ++i) {
      get<0>(id).push_back(i);
    }
    int curr = 0;
    while (id[curr].size() > 3) {
      int next = curr ^ 1;
      for (int b = 1, e = id[curr].size(); b <= e; ++b) {
        if (b % round[curr] != 0) {
          id[next].push_back(id[curr][b - 1]);
        }
      }
      // //+
      // copy(id[0].begin(), id[0].end(), ostream_iterator<int>(cout, " "));
      // cout << endl;
      // //-
      // //+
      // copy(id[1].begin(), id[1].end(), ostream_iterator<int>(cout, " "));
      // cout << endl;
      // //-
      id[curr].resize(0);
      curr = next;
    }
    cout << "1";
    for (int i = 1; i < id[curr].size(); ++i) {
      cout << ' ' << id[curr][i];
    }
    cout << endl;
  }
}
