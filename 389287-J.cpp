#include <forward_list>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

#define endl '\n'
static auto speedup = [] {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  return nullptr;
}();

static int V, E;
static vector<vector<int>> dist;       // -1 indicates no edge
static vector<vector<int>> dfs_cache;  // -2 indicates no searched

static int dfs(int visited, int to) {
  if (visited == 1) {
    return dist[0][to];
  }
  int &c = dfs_cache[visited][to];
  if (c != -2) {
    return c;
  }
  c = -1;
  for (int from = 1; from < V; ++from) {
    if ((visited & (1 << from)) != 0) {
      int d1 = dist[from][to];
      int d2 = dfs(visited & ~(1 << from), from);
      if (d1 != -1 && d2 != -1) {
        int new_c = d1 + d2;
        if (c == -1 || new_c < c) {
          c = new_c;
        }
      }
    }
  }
  return c;
}

int main() {
  cin >> V >> E;
  dist.assign(V, vector<int>(V, -1));
  dfs_cache.assign(1 << V, vector<int>(V, -2));
  while (E--) {
    int source, target;
    cin >> source >> target;
    cin >> dist[source][target];
  }
  // When every point is visited once,
  // calculate the minimum cost to go back to 0 again.
  cout << dfs(((1 << V) - 1), 0) << endl;
  // We can use bfs, too, but it's more complicated and error-prone.
}
