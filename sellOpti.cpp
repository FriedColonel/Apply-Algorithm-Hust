#include <bits/stdc++.h>
#define N 100000

using namespace std;

int n, l1, l2;
int a[N];
int f[N];

void input() {
  cin >> n >> l1 >> l2;
  for (int i = 0; i < n; i++)
    scanf("%d", &a[i]);
}

void print() {
  for (int i = 0; i < n; i++)
    cout << f[i] << " ";
  cout << endl;
}

void solve() {
  f[0] = a[0];
  for (int i = 1; i < n; i++) {
    if (i < l1)
      f[i] = max(a[i], f[i-1]);
    if (i >= l1)
      f[i] = max(a[i] + f[i-l1], f[i-1]);
  }
  cout << f[n-1];
}

int main(int argc, char *argv[]) {
  input();
  solve();
  return 0;
}
