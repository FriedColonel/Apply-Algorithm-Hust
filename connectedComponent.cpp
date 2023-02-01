#include <bits/stdc++.h>
#define N 1000001

using namespace std;

int n,m;
vector<int> A[N];
int cc[N];
int nbCC;

void input() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; i++) {
    int u,v;
    scanf("%d%d", &u, &v);
    A[u].push_back(v);
    A[v].push_back(u);
  }
}

void DFS(int u) {
  cc[u] = nbCC;
  for (int i = 0; i < A[u].size(); i++) {
    int v = A[u][i];
    if (cc[v] == 0) {
      DFS(v);
    }
  }
}

void DFS() {
  for (int v = 1; v<=n; v++) cc[v] = 0;
  nbCC = 0;
  for (int v = 1; v <= n; v++) {
    if (cc[v] == 0) {
      nbCC++;
      DFS(v);
    }
  }
}

void print() {
  for (int i = 1; i <= nbCC; i++) {
    cout << "Connected component " << i << ": ";
    for (int u = 1; u <= n; u++) {
      if (cc[u] == i) cout << u << " ";
    }
    cout << endl;
  }
}

int main(int argc, char const *argv[])
{
  input();
  DFS();
  // cout << nbCC;
  print();
  return 0;
}
