#include <bits/stdc++.h>
#define N 20

using namespace std;

int n;
int w[N];
vector<int> A[N];

void input() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    scanf("%d", w[i]);
  }
  for (int i = 1; i < n; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    A[u].push_back(v);
    A[v].push_back(u);
  }
}

void solve() {

}

int main(int argc, char const *argv[]) {
  input();
  solve();
  return 0;
}
