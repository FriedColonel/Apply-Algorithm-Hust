// Generate ways to represent n by sum of k non-decreasing positive integers
#include <bits/stdc++.h>

using namespace std;

int k, n;
int a[41];

void input() {
  cin >> k >> n;
  a[0] = 1;
}

bool check(int value, int sum) {
  if (sum < value) return false;
  return true;
}

void print() {
  for (int i = 1; i <= k; i++) {
    cout << a[i] << " ";
  }
  cout << endl;
}

void TRY(int i, int sum) {
  for (int j = a[i - 1]; j <= sum; j++) {
    if (check(j, sum)) {
      a[i] = j;
      if (i == k) {
        if (sum - j == 0) print();
      } else TRY(i + 1, sum - j);
    }
  }
}

int main(int argc, char const *argv[]) {
  input();
  TRY(1, n);
  return 0;
}
