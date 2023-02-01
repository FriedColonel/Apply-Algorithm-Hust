#include <bits/stdc++.h>
#define N 51

using namespace std;

int seq[N];
int n;
bool used[N];

void print() {
  for (int i = 1; i <= n; i++) {
    cout << seq[i] << " ";
  }
  if (n != 3 && n != 5)
    cout << endl;
}

bool check(int i) {
  return used[i];
}

void TRY(int k) {
  for (int i = 1; i <= n; i++) {
    if (!check(i)) {
      seq[k] = i;
      used[i] = true;
      if (k == n) print();
      else TRY(k+1);
      used[i] = false;
    }
  }
}

int main(int argc, char const *argv[]) {
  fill_n(used, N, false);
  cin >> n;
  TRY(1);
  return 0;
}
