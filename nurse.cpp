#include <bits/stdc++.h>
#define N 2000

using namespace std;

int n, k1, k2;
int S0[N], S1[N];

void input() {
  cin >> n >> k1 >> k2;
}

void solve() {
  for (int i = 0; i < n; i++) {
    S0[i] = 0; S1[i] = 0;
  }

  S0[1] = 1; S1[k1] = 1; S0[0] = 1;

  for (int i = 2; i <= n; i++) {
    S0[i] = S1[i-1];
    S1[i] = 0;
    for (int j = k1; j <= k2; j++) {
      if (i-j >= 0) {
        S1[i] += S0[i-j];
      }
    }
  }

  int ans = S0[n] + S1[n];
  cout << ans << endl;
}

int main(int argc, char const *argv[]) {
  input();
  solve();
  return 0;
}
