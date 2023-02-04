// Range Minimum Query
#include <bits/stdc++.h>

using namespace std;

int n;
int a[1000000];
int m;
pair<int, int> q[1000000];
int result;

void input() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  cin >> m;
  for (int i = 0; i < m; i++) {
    scanf("%d %d", &q[i].first, &q[i].second);
  }
}

void solve() {
  for (int i = 0; i < m; i++) {
    result += *min_element(a + q[i].first, a + q[i].second + 1);
  }
  cout << result;
}

int main(int argc, char const *argv[]) {
  input();
  solve();
  return 0;
}
