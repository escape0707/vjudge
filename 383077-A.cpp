#include <iostream>
using namespace std;

bool is_leap_year(int year) {
  if (year % 100 == 0) {
    return year % 400 == 0;
  }
  return year % 4 == 0;
}

int main() {
  int T;
  cin >> T;
  while (T--) {
    int year, month, day;
    char c;
    cin >> year >> c >> month >> c >> day;
    if (month == 2 && day == 29) {
      cout << -1 << endl;
      continue;
    }

    int cnt = 0;
    if (month >= 3) {
      ++year;
    }
    for (int r18 = year + 18; year < r18; ++year) {
      cnt += is_leap_year(year);
    }
    cout << cnt + 365 * 18 << endl;
  }
}
