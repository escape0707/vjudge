#include <cctype>
#include <iostream>
#include <stack>
#include <utility>

using namespace std;

#define endl '\n'
static auto speedup = [] {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  return nullptr;
}();

int main() {
  int N;
  cin >> N;
  cin.get();
  while (N--) {
    string curr;
    stack<pair<int, string>> stk;
    for (char c; (c = cin.get()) != '\n';) {
      int repeat = 1;
      if (isdigit(c)) {
        cin.unget();
        cin >> repeat >> c;
      }
      if (c == '(') {
        stk.emplace(repeat, move(curr));
        curr.clear();
      } else if (c == ')') {
        string to_repeat = move(curr);
        repeat = stk.top().first;
        curr = move(stk.top().second);
        stk.pop();
        while (repeat--) {
          curr += to_repeat;
        }
      } else {
        curr += string(repeat, c);
      }
    }
    cout << curr << endl;
  }
}
