#include <iostream>
#include <vector>

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
  while (N--) {
    int num;
    cin >> num;
    vector<int> odd_collection;
    while (num != 1) {
      if (num & 1) {
        odd_collection.push_back(num);
        num = num * 3 + 1;
      } else {
        num /= 2;
      }
    }
    if (odd_collection.empty()) {
      cout << "No number can be output !" << endl;
    } else {
      cout << odd_collection[0];
      for (int i = 1; i < odd_collection.size(); ++i) {
        cout << ' ' << odd_collection[i];
      }
      cout << endl;
    }
  }
}
