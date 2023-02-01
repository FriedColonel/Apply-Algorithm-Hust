#include <bits/stdc++.h>
#include <iterator>
#include <stack>
#define N 1000000

using namespace std;

int n;
int a[N];
int count[N];

void input() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
}

void solve() {
  int result = 0;
  multiset<int> s;
  s.insert(a[0]);
  multiset<int>::iterator itset;
  for (int i = 1; i < n; i++) {
    s.insert(a[i]);
    itset = s.upper_bound(a[i]);
    result += distance(itset, s.end());
  }
  cout << result;
}

int main(int argc, char *argv[]) {
  input();
  solve();
  return 0;
}
