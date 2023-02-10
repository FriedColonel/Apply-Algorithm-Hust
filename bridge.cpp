#include <bits/stdc++.h>
#define MAX 100002

using namespace std;

int n,m;
vector<int> a[MAX];
int nbBridge = 0;
int nbArticulation = 0;
int num[MAX];
int low[MAX];
int t = 0;

void input() {
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int u,v;
    scanf("%d%d",&u,&v);
    a[u].push_back(v);
    a[v].push_back(u);
  }
}

void printLowAndHigh() {
  for (int i = 1; i <= n; i++) {
    cout << i << " " << low[i] << " " << num[i] << endl;
  }
}

void dfs(int u) {
  num[u] = low[u] = ++t;
  for (int i = 0; i < a[u].size(); i++) {
    int v = a[u][i];
    if (num[v] == 0) {
      dfs(v);
      low[u] = min(low[u],low[v]);
      if (low[v] >= num[u]) {
        nbBridge++;
      }
    } else {
      low[u] = min(low[u],num[v]);
    }
  }
}

void countBridge() {
  for (int i = 1; i <= n; i++) {
    if (num[i] == 0) {
      dfs(i);
    }
  }
}

int main(int argc, char const *argv[]) {
  input();
  dfs(1);
  cout << nbBridge << endl;
  // printLowAndHigh();
  return 0;
}
