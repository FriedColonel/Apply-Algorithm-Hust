#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<int> a[100000];
vector<int> topoSort;
int d[100000];

void input() {
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    a[u].push_back(v);
    d[v]++;
  }
}

void topo() {
  queue<int> q;

  for (int i = 1; i <= n; i++) {
    if (d[i] == 0) {
      q.push(i);
    }
  }

  while (!q.empty()) {
    int u = q.front();
    q.pop();
    topoSort.push_back(u);

    for (int i = 0; i < a[u].size(); i++) {
      int v = a[u][i];
      d[v]--;
      if (d[v] == 0) {
        q.push(v);
      }
    }
  }
}

int main(int argc, char const *argv[]) {
  input();
  topo();
  return 0;
}
