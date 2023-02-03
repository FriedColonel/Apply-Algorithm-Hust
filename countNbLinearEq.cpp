// Count solutions to an integer linear equation
#include <bits/stdc++.h>
#define N 10000

using namespace std;

int n, m;
int a[N], p[N];
int result = 0;

void input() {
  cin >> n >> m;
  for (int i = 0; i < n; i++)
    scanf("%d", &a[i]);
}

bool check(int value, int index, int sum) {
  if (sum < value*a[index]) return false;
  return true;
}

void print() {
  for (int i = 0; i < n; i++) {
    cout << p[i] << " ";
  }
  cout << endl;
}

void TRY(int k, int sum) {
  for (int j = 1; j <= sum; j++) {
    if (check(j, k, sum)) {
      p[k] = j;
      if (k == n - 1) {
        if (sum - j * a[k] == 0) result++;
      } else TRY(k + 1, sum - j * a[k]);
    }
  }
}

int main(int argc, char const *argv[]) {
  input();
  TRY(0, m);
  cout << result;
  return 0;
}
