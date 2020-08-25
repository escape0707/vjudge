#include <iostream>
#include <string>

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
  for (int i = 0; i < N; ++i) {
    if (i != 0) {
      cout << endl;
    }
    char c;
    int height;
    cin >> c >> height;
    const int weight = height / 6 + 1;
    const int upper_height = (height - 3) / 2;
    const int lower_r = upper_height + ((~height) & 1);

    string mid = string(weight, ' ') + string(lower_r, c) + "\n";
    string left_right =
        string(weight, c) + string(lower_r, ' ') + string(weight, c) + "\n";
    cout << mid;
    for (int j = 0; j < upper_height; ++j) {
      cout << left_right;
    }
    cout << mid;
    for (int j = 0; j < lower_r; ++j) {
      cout << left_right;
    }
    cout << mid;
  }
}
