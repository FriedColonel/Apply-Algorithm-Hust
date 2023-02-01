#include <bits/stdc++.h>
#define N 51

using namespace std;

int n;
int s[N];

void solve() {
  memset(s, 0, sizeof(s));
  s[0] = 1;
  for (int i = 1; i < n; i++) {
    for (int j = i; j <= n; j++) {
      s[j] += s[j-i];
    }
  }
  cout << s[n] + 1;
}

int main(int argc, char const *argv[]) {
  cin >> n;
  solve();
  return 0;
}
