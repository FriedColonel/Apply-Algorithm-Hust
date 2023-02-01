// chưa xong
#include <bits/stdc++.h>
#define N 999

using namespace std;

int k, n;

void solve() {
  unsigned long long result = n;
  const unsigned long long M = 1000000007;
  if (k > n/2) k = n - k;
  for (int i = 2; i <= k; i++) {
    result = (result * (n - i + 1) / i) % M;
  }
  cout << result;
}

int main(int argc, char const *argv[]) {
  cin >> k >> n;
  solve();
  return 0;
}
