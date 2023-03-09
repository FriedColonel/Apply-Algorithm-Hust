#include <bits/stdc++.h>
#define MAX 1000

using namespace std;

int r, c;
int matrix[MAX][MAX];

void input() {
  cin >> r >> c;
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      scanf("%d", &matrix[i][j]);
    }
  }
}

int maxHist(int row[]) {
  stack<int> s;

  int maxArea = 0;
  int top;
  int areaWithTop;

  int i = 0;
  while (i < c) {
    if (s.empty() || row[s.top()] <= row[i]) {
      s.push(i++);
    } else {
      top = s.top();
      s.pop();

      areaWithTop = row[top] * (s.empty() ? i : i - s.top() - 1);

      if (maxArea < areaWithTop) {
        maxArea = areaWithTop;
      }
    }
  }

  while (!s.empty()) {
    top = s.top();
    s.pop();

    areaWithTop = row[top] * (s.empty() ? c : c - s.top() - 1);

    if (maxArea < areaWithTop) {
      maxArea = areaWithTop;
    }
  }

  return maxArea;
}

void maxArea() {
  int row[c];
  // fill row with 0
  for (int i = 0; i < c; i++) {
    row[i] = 0;
  }
  int maxArea = 0;
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      if (matrix[i][j] == 0) {
        row[j] = 0;
      } else {
        row[j] += matrix[i][j];
      }
    }
    maxArea = max(maxArea, maxHist(row));
  }
  cout << maxArea << endl;
}

int main(int argc, char const *argv[]) {
  input();
  maxArea();
  return 0;
}
