#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<int> a[100000];
int num[100000], low[100000];
int visisted[100000];
int t = 0;
vector<pair<int,int>> bridges;
int cntArticulation = 0;
bool isArticulation[100000];
int p[100000];
int nbChild[100000];

void input() {
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    a[u].push_back(v);
    a[v].push_back(u);
  }
}

// dfs to find briges and articulation points
void dfs(int start, int parent) {
  visisted[start] = 1;
  num[start] = low[start] = ++t;
  p[start] = parent;

  for (int i = 0; i < a[start].size(); i++) {
    int v = a[start][i];
    if (v == parent) {
      continue;
    }

    if (visisted[v] == 0) {
      nbChild[start]++;
      dfs(v, start);
      low[start] = min(low[start], low[v]);
      if (low[v] > num[start]) {
        bridges.push_back({start, v});
      }
    } else {
      low[start] = min(low[start], num[v]);
    }
  }
}

void printNumLow() {
  for (int i = 1; i <= n; i++) {
    cout << i << ": " << num[i] << " " << low[i] << endl;
  }
}

void printParent() {
  for (int i = 1; i <= n; i++) {
    cout << i << ": " << p[i] << endl;
  }
}

void countArticulation() {
  for (int i = 1; i <= n; i++) {
    if (p[i] == -1 && nbChild[i] > 1) {
      isArticulation[i] = true;
    }
    if (p[i] != -1 && p[p[i]] != -1 && low[i] >= num[p[i]]) {
      isArticulation[p[i]] = true;
    }
  }
  for (int i = 1; i <= n; i++) {
    if (isArticulation[i]) {
      cntArticulation++;
    }
  }
}

void solve() {
  for (int i = 1; i <= n; i++) {
    visisted[i] = 0;
  }

  for (int i = 1; i <= n; i++) {
    if (visisted[i] == 0) {
      dfs(i, -1);
    }
  }

  // printParent();

  countArticulation();

  cout << cntArticulation << " " << bridges.size() << endl;
}

int main(int argc, char const *argv[]) {
  input();
  solve();
  return 0;
}
