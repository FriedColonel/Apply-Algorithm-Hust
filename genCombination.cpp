#include <bits/stdc++.h>
#define N 101

using namespace std;

int n, key;
int comb[N];

void print() {
  for (int i = 1; i <= n; i++) {
    cout << comb[i] << " ";
  }
  cout << endl;
}

bool check(int k, int i) {
  if (k > 1 && comb[k-1] >= i) return false;
  return true;
}

void TRY(int k) {
  for (int i = 1; i <= key; i++) {
    if (check(k, i)) {
      comb[k] = i;
      if (k == n) print();
      else TRY(k+1);
    }
  }
}

int main(int argc, char const *argv[])
{
  cin >> n >> key;
  TRY(1);
  return 0;
}
