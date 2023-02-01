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

void TRY(int k) {
  for (int i = 0; i < 2; i++) {
    seq[k] = i;
    if (k == n) print();
    else TRY(k+1);
  }
}

int main(int argc, char const *argv[])
{
  cin >> n;
  TRY(1);
  return 0;
}
