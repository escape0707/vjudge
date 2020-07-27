#include <fstream>
#include <random>
#include <unordered_set>
#include <vector>
using namespace std;

ofstream fout("input.txt");

static int random_int(int a, int b) {
  static random_device rd;
  static default_random_engine e(rd());
  uniform_int_distribution<> u(a, b);
  return u(e);
}

int main() {
  constexpr int CHILD_CNT = 10;
  int BALL_CNT = random_int(0, CHILD_CNT);
  vector<unordered_set<int>> friendCollectionById(CHILD_CNT);
  for (int child_id = 0; child_id < CHILD_CNT; ++child_id) {
    int random_cnt = random_int(0, CHILD_CNT - 1);
    for (int j = 0; j < random_cnt; ++j) {
      int friend_id = random_int(0, CHILD_CNT - 1);
      friendCollectionById[child_id].insert(friend_id);
      friendCollectionById[friend_id].insert(child_id);
    }
  }

  fout << CHILD_CNT << ' ' << BALL_CNT << endl;
  for (const auto &friendCollection : friendCollectionById) {
    fout << friendCollection.size();
    for (auto friend_id : friendCollection) {
      fout << ' ' << friend_id;
    }
    fout << endl;
  }
}
