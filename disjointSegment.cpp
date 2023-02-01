#include <bits/stdc++.h>

using namespace std;
#define N 100000

struct Time
{
  int start, end;
};

Time X[N];
int A[N];
int n;

bool compareInterval(Time i1, Time i2)
{
  return (i1.end < i2.end);
}

void check()
{
  sort(X, X + n, compareInterval);
  int count = 1;
  A[1] = X[1].end;
  for (int i = 2; i <= n; i++)
  {
    if (X[i].start > A[count])
    {
      count++;
      A[count] = X[i].end;
    }
  }

  cout << count;
}

int main(int argc, char const *argv[])
{
  scanf("%d", &n);
  for (int i = 1; i <= n; i++)
  {
    scanf("%d", &X[i].start);
    scanf("%d", &X[i].end);
  }
  check();
  return 0;
}
