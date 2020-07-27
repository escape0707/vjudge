#include <algorithm>
#include <array>
#include <iostream>
#include <vector>
using namespace std;

static constexpr int MAX_CNT = 10;
static array<array<bool, MAX_CNT>, MAX_CNT> is_friend;
static int kid_cnt, ball_cnt;

static bool check_friendship(int kid_id, const vector<int> &group) {
  return all_of(begin(group), end(group), [&kid_id](const int kid_in_group_id) {
    return is_friend[kid_id][kid_in_group_id];
  });
}

static bool dfs() {
  static vector<vector<int>> group_collection(ball_cnt);
  static int current_group_count = 0;
  static int kid_id = 0;
  for (auto
           group_iter = begin(group_collection),
           e = begin(group_collection) + min(current_group_count + 1, ball_cnt);
       group_iter != e; ++group_iter) {
    if (check_friendship(kid_id, *group_iter)) {
      if (group_iter->empty()) {
        ++current_group_count;
      }
      group_iter->push_back(kid_id);
      ++kid_id;
      if (kid_id == kid_cnt || dfs()) {
        return true;
      }
      --kid_id;
      group_iter->pop_back();
      if (group_iter->empty()) {
        --current_group_count;
      }
    }
  }
  return false;
}

int main() {
  cin >> kid_cnt >> ball_cnt;
  for (int kid_id = 0; kid_id < kid_cnt; ++kid_id) {
    int friend_cnt;
    cin >> friend_cnt;
    for (int friend_no = 0; friend_no < friend_cnt; ++friend_no) {
      int friend_id;
      cin >> friend_id;
      is_friend[kid_id][friend_id] = true;
      // is_friend[friend_id][kid_id] = true;
    }
  }

  cout << (dfs() ? "YES" : "NO") << endl;
}
