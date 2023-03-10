#include <bits/stdc++.h>
#define N 21

using namespace std;

int n;
int c[N][N];
int F[N][(1 << (N+1))];

void input() {
  cin >> n;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
      scanf("%d", &c[i][j]);
}

bool contains(int i, unsigned int s) {
  if (s & (1 << i)) return true; return false;
}

unsigned int remove(int i, unsigned int s) {
  return (s & (~(1 << i)));
}

int TSP(int i, unsigned int s) {
  if (s == 0) {
    F[i][s] = c[i][0];
    return F[i][s];
  }
  if (F[i][s] < 0) {
    F[i][s] = 1000000000;
    for (int j = 1; j <= n; j++) {
      if (contains(j, s) && j != i) {
        unsigned int sj = remove(j, s);
        int tj = TSP(j,sj) + c[i][j];
        if (F[i][s] > tj) {
          F[i][s] = tj;
        }
      }
    }
  }
  return F[i][s];
}

int main(int argc, char const *argv[]) {
  input();

  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= (1 << n - 1); j++)
      F[i][j] = -1;

  unsigned int s = (1 << n) - 1;
  int ans = TSP(1, s);
  cout << ans;
  return 0;
}
