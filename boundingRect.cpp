// solve Bounding rectangle
#include <bits/stdc++.h>

using namespace std;

int n;
int minX = 10000, maxX = -10000, minY = 10000, maxY = -10000;

void solve() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    int x1, x2, y1, y2;
    scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
    if (x1 < minX) minX = x1;
    if (x2 < minX) minX = x2;
    if (y1 < minY) minY = y1;
    if (y2 < minY) minY = y2;
    if (x1 > maxX) maxX = x1;
    if (x2 > maxX) maxX = x2;
    if (y1 > maxY) maxY = y1;
    if (y2 > maxY) maxY = y2;
  }
  cout << (maxX - minX)*(maxY - minY);
}

int main(int argc, char const *argv[]) {
  solve();
  return 0;
}
