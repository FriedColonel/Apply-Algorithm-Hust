#include <bits/stdc++.h>

using namespace std;

int nbTest;
int n[100000];
vector<int> a[100000];

void input() {
  cin >> nbTest;
  for (int i = 0; i < nbTest; i++) {
    cin >> n[i];
    for (int j = 0; j < n[i]; j++) {
      int x;
      cin >> x;
      a[i].push_back(x);
    }
  }
}

void solve() {
  vector<int> t;
  for (int i = 0; i < nbTest; i++) {
    int result = 0;
    while (a[i].size() > 1) {
      int maxTime = a[i][0] + a[i][1];
      for (int j = 0; j < a[i].size(); j+=2) {
        if (j == a[i].size() - 1) {
          t.push_back(a[i][j]);
          break;
        }
        t.push_back(a[i][j] + a[i][j+1]);
        if (a[i][j] + a[i][j+1] > maxTime) {
          maxTime = a[i][j] + a[i][j+1];
        }
      }
      result += maxTime;
      a[i].clear();
      // copy t to a[i]
      for (int j = 0; j < t.size(); j++) {
        a[i].push_back(t[j]);
      }
      t.clear();
    }
    cout << result << endl;
  }
}

int main(int argc, char const *argv[]) {
  input();
  solve();
  return 0;
}
