#include <bits/stdc++.h>
#define N 10001

using namespace std;

int n, m;
int D[N];
vector<int> a[N];
int d[N];
int result = 0;
int start[N];
int visited[N];

void input() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    scanf("%d", &D[i]);
  }
  for (int i = 1; i <= m; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    a[u].push_back(v);
    d[v]++;
  }
}

void topo() {
  queue<int> q;

  for (int i = 1; i <= n; i++) {
    start[i] = 0;
    if (d[i] == 0) {
      visited[i] = 1;
      q.push(i);
    }
  }

  while (!q.empty()) {
    int u = q.front();
    q.pop();

    for (int i = 0; i < a[u].size(); i++) {
      int v = a[u][i];
      start[v] = max(start[u] + D[u], start[v]);
      d[v]--;
      if (d[v] == 0 && !visited[v]) {
        visited[v] = 1;
        q.push(v);
      }
    }
  }

  for (int i = 1; i <= n; i++) {
    result = max(result, start[i] + D[i]);
  }

  cout << result << endl;
}

int main(int argc, char const *argv[]) {
  input();
  topo();
  return 0;
}
