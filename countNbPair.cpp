// Count number of pairs of sequence of distinct integer sum equal to Q
#include <bits/stdc++.h>
#define N 1000001

using namespace std;

int n, q;
int a[N];
int result = 0;
map<int, int> m;

void input() {
  cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    m[a[i]] = i;
  }
}

void solve() {
  for (int i = 1; i <= n; i++) {
    int temp = q - a[i];
    if (m[temp] && m[temp] > i) result++;
  }
  cout << result;
}

int main(int argc, char const *argv[]) {
  input();
  solve();
  return 0;
}
