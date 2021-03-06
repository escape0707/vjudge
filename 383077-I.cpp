#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

static constexpr int MAX_CNT = 10;
static vector<vector<bool>> is_friend;
static int kid_cnt, ball_cnt;

static bool check_friendship(const int kid_id, const vector<int> &group) {
  return all_of(begin(group), end(group), [&kid_id](const int kid_in_group_id) {
    return is_friend[kid_id][kid_in_group_id];
  });
}

static vector<vector<int>> group_collection;
static int current_group_count;
static int kid_id;
static bool dfs() {
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
  while (cin >> kid_cnt >> ball_cnt) {
    is_friend.assign(kid_cnt, vector<bool>(kid_cnt, false));
    for (kid_id = 0; kid_id < kid_cnt; ++kid_id) {
      int friend_cnt;
      cin >> friend_cnt;
      while (friend_cnt--) {
        int friend_id;
        cin >> friend_id;
        is_friend[kid_id][friend_id] = true;
      }
    }

    group_collection.assign(ball_cnt, vector<int>());
    current_group_count = 0;
    kid_id = 0;
    cout << (dfs() ? "YES" : "NO") << endl;
  }
}
