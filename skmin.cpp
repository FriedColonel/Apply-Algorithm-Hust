#include <bits/stdc++.h>

using namespace std;

string s;
int k;

void input() {
  cin >> s >> k;
}

void solve() {
  vector<char> v;
  for (int i = 0; i < s.size() - k + v.size(); i++) {
    if (v.size() == 0) {
      v.push_back(s[i]);
    } else {
      if (v.back() < s[i]) {
        v.pop_back();
        v.push_back(s[i]);
      } else {
        if (v.size() < k) v.push_back(s[i]);
      }
    }
  }
  if (v.size() < k) {
    for (int i = s.size() - k + v.size(); i < s.size(); i++)
      v.push_back(s[i]);
  }
  for (int i = 0; i < v.size(); i++) {
    cout << v[i];
  }
}

int main(int argc, char const *argv[]) {
  input();
  solve();
  return 0;
}
