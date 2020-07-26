#include <iostream>
#include <array>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int N;
  while (cin >> N && N > 0) {
    array<int, 101> class_rank = {};
    int score;
    while (N--) {
      cin >> score;
      ++class_rank[score];
    }
    cin >> score;
    cout << class_rank[score] << endl;
  }
}
