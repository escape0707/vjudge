#include <iostream>
#include <set>

using namespace std;

#define endl '\n'
static auto speedup = [] {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  return nullptr;
}();

int main() {
  int n, m;
  while (cin >> n >> m) {
    set<int> a;
    int tmp;
    while (n--) {
      cin >> tmp;
      a.emplace(tmp);
    }
    while (m--) {
      cin >> tmp;
      a.emplace(tmp);
    }
    cout << *(a.cbegin());
    for (auto b = ++a.cbegin(), e = a.cend(); b != e; ++b) {
      cout << ' ' << *b;
    }
    cout << endl;
  }
}
