#include <bits/stdc++.h>

using namespace std;

int n, m;

int solve() {
  int u = min(n, m);
  int v = max(n, m);
  int res = sqrt(2 * u);
  if ((res + 1) * (res + 1) - (res + 1) * (res + 1) / 2 <= v && (res + 1) * (res + 1) / 2 <= u)
    return res + 1;
  return res;
}

int main(int argc, char const *argv[]) {
  cin >> n >> m;
  cout << solve();
  return 0;
}
