#include <iostream>
#include <map>
#include <string>
using namespace std;

static const map<string, int> spell_to_num = {
    {"zero", 0}, {"one", 1}, {"two", 2},   {"three", 3}, {"four", 4},
    {"five", 5}, {"six", 6}, {"seven", 7}, {"eight", 8}, {"nine", 9}};

int main() {
  while (cin) {
    int A = 0, B = 0;
    string curr;
    cin >> curr;
    while (curr != "+") {
      A = A * 10 + spell_to_num.at(curr);
      cin >> curr;
    }
    cin >> curr;
    while (curr != "=") {
      B = B * 10 + spell_to_num.at(curr);
      cin >> curr;
    }
    if (A == 0 && B == 0) {
      break;
    }
    cout << A + B << endl;
  }
}
