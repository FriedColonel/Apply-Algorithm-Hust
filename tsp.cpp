#include <bits/stdc++.h>
#define N 50
#define M 100000000

using namespace std;

int a[N];
int n;
int c[N][N];
int F[N][M];

void input() {
  cin >> n;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
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
    F[i][s] = 1e9;
    for (int j = 0; j < n-1; j++) {
      if (contains(j, s)) {
        unsigned int sj = remove(j, s);
        int tj = TSP(j,s) + c[i][j];
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
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < M; j++) {
      F[i][j] = -1;
    }
  }
  unsigned int s = (1 << n) - 1;
  int ans = TSP(0, s);
  cout << ans;
  return 0;
}
