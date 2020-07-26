#include <iostream>
#include <array>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int N;
  while (cin >> N && N != 0) {
    array<int, 101> sheet = {};
    int score;
    while (N--) {
      cin >> score;
      ++sheet[score];
    }
    cin >> score;
    cout << sheet[score] << endl;
  }
}
