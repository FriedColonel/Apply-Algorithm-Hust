#include <iostream>
#define N 21

using namespace std;

int seq[N];
int n;

void print() {
  for (int i = 1; i <= n; i++) {
    cout << seq[i];
  }
  cout << endl;
}

bool check(int k, int i) {
  if (k == 0 || i == 0) return true;
  return seq[k-1] == 0;
}

void TRY(int k) {
  for (int i = 0; i < 2; i++) {
    if (check(k, i)) {
      seq[k] = i;
      if (k == n) print();
      else TRY(k + 1);
    }
  }
}

int main(int argc, char const *argv[])
{
  cin >> n;
  TRY(1);
  return 0;
}
