#include <bits/stdc++.h>
#define N 1001

using namespace std;

int n, t, d;
int A[N], T[N];
int tb[N][N];

void input() {
  cin >> n >> t >> d;
  for (int i = 1; i <= n; i++)
    scanf("%d", &A[i]);
  for (int i = 1; i <= n; i++)
    scanf("%d", &T[i]);
}

void solve() {
  for (int time = 1; time <= t; time++) {
    // cout << time << ": ";
    for (int i = 1; i <= n; i++) {
      if (time == 1) {
        if (T[i] == time) tb[time][i] = A[i];
        else tb[time][i] = 0;
      } else {
        if (T[i] > time) tb[time][i] = 0;
        else if (i == 1 || T[i] == time) tb[time][i] = A[i];
        else if (i <= d && T[i] < time) tb[time][i] = A[i] + *max_element(tb[time - T[i]] + 1, tb[time - T[i]] + i);
        else if (i > d && T[i] < time) tb[time][i] = A[i] + *max_element(tb[time - T[i]] + i - d, tb[time - T[i]] + i);
      }
    }
  }
  cout << *max_element(tb[t] + 1, tb[t] + n + 1);
}

int main(int argc, char const *argv[]) {
  input();
  solve();
  return 0;
}
