#include <algorithm>
#include <iostream>
#include <iterator>
#include <numeric>
#include <vector>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> denomination_collection;
  denomination_collection.reserve(m);
  copy(istream_iterator<int>(cin), istream_iterator<int>(),
       back_inserter(denomination_collection));

  vector<int> coin_cnt(n + 1, numeric_limits<int>::max());
  coin_cnt[0] = 0;
  for (int curr = 1; curr <= n; ++curr) {
    for (int denomination : denomination_collection) {
      if (curr >= denomination) {
        coin_cnt[curr] = min(coin_cnt[curr], coin_cnt[curr - denomination] + 1);
      }
    }
  }

  cout << coin_cnt[n] << endl;
}
