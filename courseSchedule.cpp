#include <bits/stdc++.h>

using namespace std;

int n;

int main(int argc, char const *argv[]) {
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  sort(a.begin(), a.end());

  int cnt = 0;

  while (n > 0) {
    int m = 6;
    // get first element in array
    while (m > 0 && a.size() > 0) {
      if (m - a[0] > 0) m -= a[0];
      else break;
      a.erase(a.begin());
    }
    n = a.size();
    cnt++;
  }
  cout << cnt;
  return 0;
}
