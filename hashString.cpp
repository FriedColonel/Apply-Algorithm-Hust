// Hash overs strings
#include <bits/stdc++.h>
#define N 100001

using namespace std;

int n, m;
string I[N];

void input() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    fflush(stdin);
    cin >> I[i];
  }
}

unsigned long fast_mod(const unsigned long input, const int ceil) {
  return input >= ceil ? input % ceil : input;
}

void print() {
  for (int i = 1; i <= n; i++) {
    cout << I[i] <<endl;
  }
}

void solve() {
  for (int i = 1; i <= n; i++) {
    unsigned long result = 0;
    int k = I[i].size();
    for (int j = 0; j < k; j++) {
      result += fast_mod(int(I[i][j])*pow(256, k-j-1), m);
      result = fast_mod(result, m);
      // cout << int(I[i][j]) << " ";
    }
    cout << result << endl;
  }
}

int main(int argc, char const *argv[]) {
  input();
  solve();
  // print();
  return 0;
}
