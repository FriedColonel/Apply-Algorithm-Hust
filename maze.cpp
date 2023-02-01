#include <bits/stdc++.h>
#define N 1001

using namespace std;

int n,m,r,c;
int A[N][N];
int step[N][N];
int dr[] = {-1, 1};

void input() {
  cin >> n >> m >> r >> c;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      scanf("%d", &A[i][j]);
    }
  }
}

int solve() {
  queue<pair<int,int>> q;
  q.push(make_pair(r,c));
  step[r][c] = 1;
  while(!q.empty()) {
    pair<int,int> p = q.front(); q.pop();
    if (p.first == n || p.second == m || p.first == 1 || p.second == 1) return step[p.first][p.second];
    else {
      for (int i = 0; i < 2; i++) {
        if (step[p.first + dr[i]][p.second] == 0 && A[p.first + dr[i]][p.second] == 0) {
          q.push(make_pair(p.first + dr[i], p.second));
          step[p.first + dr[i]][p.second] = step[p.first][p.second] + 1;
        }
        if (step[p.first][p.second + dr[i]] == 0 && A[p.first][p.second + dr[i]] == 0) {
          q.push(make_pair(p.first, p.second + dr[i]));
          step[p.first][p.second + dr[i]] = step[p.first][p.second] + 1;
        }
      }
    }
  }
  return -1;
}

int main(int argc, char const *argv[]) {
  input();
  cout << solve();
  return 0;
}
