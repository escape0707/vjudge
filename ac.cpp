#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;

#define PF(x) (scanf("%d", &x))
#define PT(x, y) (scanf("%d%d", &x, &y))
#define PR(x) (printf("%d\n", x))
#define PRT(x, y) (printf("%d %d\n", x, y))
#define M 20

int maps[M][M];
int n, m;
int mins = 100;

vector<vector<int> > G(15);

bool isele(int agroup, int nele) {
  for (int i = 0; i < (int)G[agroup].size(); i++)
    if (!maps[G[agroup][i]][nele]) return false;
  return true;
}
void dfs(int ngroup, int which) {
  if (which == n) {
    if (ngroup + 1 < mins) mins = ngroup + 1;
    return;
  }
  if (ngroup + 1 >= mins) return;

  for (int i = 0; i <= ngroup; i++) {
    if (isele(i, which)) {
      G[i].push_back(which);
      dfs(ngroup, which + 1);
      G[i].erase(G[i].end() - 1);
    }
  }
  G[ngroup + 1].push_back(which);
  dfs(ngroup + 1, which + 1);
  G[ngroup + 1].erase(G[ngroup + 1].end() - 1);
  //自己写代表的时候最后一行是没有加的，当无路可走的时候加这行一交发现对了，奇迹！！
}
void sovle() {
  mins = 100;
  for (int i = 0; i <= n; i++)
    if (!G[i].empty()) G[i].clear();
  G[0].push_back(0);
  dfs(0, 1);
}
void init() {
  while (scanf("%d%d", &n, &m) != EOF) {
    memset(maps, 0, sizeof(maps));
    for (int i = 0; i < n; i++) {
      int num;
      PF(num);
      int ele;
      for (int j = 0; j < num; j++) {
        PF(ele);
        maps[i][ele] = 1;
      }
    }
    if (m > n) {
      puts("NO");
      continue;
    }
    sovle();
    // cout<<mins<<endl;
    if (mins <= m)
      puts("YES");
    else
      puts("NO");
  }
  return;
}
int main() {
  init();
  return 0;
}
