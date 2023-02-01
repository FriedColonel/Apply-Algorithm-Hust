#include <bits/stdc++.h>
#define N 1000001

using namespace std;

int n, M;
set<int> a;
int ans = 0;

void solve() {
  for(set<int>::iterator i = a.begin(); i != a.end(); i++) {
    set<int>::iterator k = a.find(M - *i);
    if (k == i || k == a.end())
      continue;
    ans++;
  }
  cout << ans/2;
}

int main(int argc, char const *argv[])
{
  cin >> n >> M;
  int tmp;
  for (int i = 0; i < n; i++) {
    scanf("%d", &tmp);
    a.insert(tmp);
  }
  solve();
  return 0;
}
