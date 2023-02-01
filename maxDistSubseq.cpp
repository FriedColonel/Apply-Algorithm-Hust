#include <bits/stdc++.h>
#define N 20
#define MAX 100

using namespace std;

// int test[N];
// int n[N], c[N];
// int sequence[N][MAX];
// int ans[N];
int n = 6, c = 4;
int seq[6] = {1,10,12,15,21,34};
int ans;

void input() {
  // cin >> n >> c;
  for (int i = 0; i < n; i++) {
    cin >> seq[i];
  }
}

int main(int argc, char *argv[]) {
  // input();
  sort(seq, seq + n);
  for (int d = seq[n-1] - seq[0]; d >= 1; d--) {
    int cnt = 1, last = 0;
    for (int i = 1; i < n; i++) {
      if (seq[i] >= seq[last] + d){
        ++cnt;
        last = i;
      }
    }
    if (cnt >= c) {
      cout << d << "\n";
      return 0;
    }
  }

  return 0;
}
