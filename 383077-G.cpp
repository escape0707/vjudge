#include <algorithm>
#include <iostream>
#include <string>
#include <utility>
#include <vector>
using namespace std;

int main() {
  int N, M;
  cin >> N;
  while (N--) {
    cin >> M;
    vector<pair<string, string>> id_by_time;
    while (M--) {
      string id, sign_in, sign_out;
      cin >> id >> sign_in >> sign_out;
      id_by_time.emplace_back(sign_in, id);
      id_by_time.emplace_back(sign_out, id);
    }
    sort(begin(id_by_time), end(id_by_time));
    cout << id_by_time.front().second << ' ' << id_by_time.back().second
         << endl;
  }
}
