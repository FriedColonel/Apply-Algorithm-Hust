#include <bits/stdc++.h>
#define MAXN 31
#define MAXM 11

using namespace std;

int m, n;
bool canTeach[MAXM][MAXN];

void init() {
  memset(canTeach, false, sizeof(canTeach));
}

void input() {
  cin >> m >> n;
  for (int i = 1; i <= m; i++) {
    int k;
    cin >> k;
    for (int j = 1; j <= k; j++) {
      int x;
      scanf("%d", &x);
      canTeach[i][x] = true;
    }
  }
}

int main(int argc, char const *argv[]) {
  return 0;
}
