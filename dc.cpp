#include <algorithm>
#include <iostream>
#define INT_MIN -1e9

using namespace std;

int arr[8] = {-2, -3, 4, -1, -2, 1, 5, -3};
int maxSoFar = INT_MIN;
int maxEndingHere = 0;
int n = 8;

int maxSumSubarr() {
  for (int i = 0; i < n; i++) {
    maxEndingHere += arr[i];

    if (maxEndingHere > maxSoFar)
      maxSoFar = maxEndingHere;

    if (maxEndingHere < 0)
      maxEndingHere = 0;
  }
  return maxSoFar;
}

int main(int argc, char *argv[]) {
  cout << maxSumSubarr();
  return 0;
}
