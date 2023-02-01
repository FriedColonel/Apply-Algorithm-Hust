#include <bits/stdc++.h>
#include <cstdio>
#define N 10001

using namespace std;

int n, m;
int X[N], Y[N];
int S[N][N];
char trace[N][N];

void input() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++)
    scanf("%d", &X[i]);
  for (int i = 1; i <= m; i++)
    scanf("%d", &Y[i]);
}

void solveBottomUp() {
  for (int i = 0; i <= n; i++)
    S[i][0] = 0;
  for (int j = 0; j <= m; j++)
    S[0][j] = 0;

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (X[i] == Y[j]) {
        S[i][j] = S[i - 1][j - 1] + 1;
        trace[i][j] = 'D';
      } else {
        if (S[i - 1][j] > S[i][j - 1]) {
          S[i][j] = S[i - 1][j];
          trace[i][j] = 'U';
        } else {
          S[i][j] = S[i][j - 1];
          trace[i][j] = 'L';
        }
      }
    }
  }
  int res = S[n][m];
  int i = n;
  int j = m;
  while (i >= 1 && j >= 1) {
    if (trace[i][j] == 'D') {
      cout << X[i] << " ";
      i = i - 1;
      j = j - 1;
    }
    if (trace[i][j] == 'L') {
      i = i - 1;
    }
    if (trace[i][j] == 'U') {
      j = j - 1;
    }
  }
}

int F(int i, int j) {
  if (i == 0 || j == 0) {
    S[i][j] = 0;
    return S[i][j];
  }
  if (S[i][j] == -1) {
    if (X[i] == Y[j]) {
      S[i][j] = F(i - 1, j - 1) + 1;
    } else {
      S[i][j] = max(F(i - 1, j), F(i, j - 1));
    }
  }
  return S[i][j];
}

void solveTopDown() {
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= m; j++) {
      S[i][j] = -1;
    }
  }
}

int main(int argc, char *argv[]) {
  input();
  solveBottomUp();
  return 0;
}
