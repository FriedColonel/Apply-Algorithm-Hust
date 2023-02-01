#include <bits/stdc++.h>

using namespace std;

const int N = 100001;
int n, m;
vector<int> a[N];
bool visisted[N];

void input() {
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    a[u].push_back(v);
    a[v].push_back(u);
  }
}

void DFS(int u) {
  visisted[u] = true;
  cout << u << " ";
  for(int i = 0; i < a[u].size(); i++) {
    if (!visisted[a[u][i]])
      DFS(a[u][i]);
  }
}

int main(int argc, char const *argv[]) {
  input();
  DFS(1);
  return 0;
}
