#include <iostream>

using namespace std;

int graph[9][9];
bool maxRow[9][10];
bool maxCol[9][10];
bool markSquare[3][3][10];

bool check(int v, int r, int c) {
  return maxRow[r][v] == false && maxCol[c][v] == false &&
         markSquare[r / 3][c / 3][v] == false;
}

void solution() {
  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      cout << graph[i][j] << " ";
    }
    cout << endl;
  }
  cout << endl;
}

// thử giá trị cho r và c
void TRY(int r, int c) {
  if (graph[r][c] != 0) {
    if (r == 8 && c == 8)
      solution();
    else {
      if (c < 8)
        TRY(r, c + 1);
      else
        TRY(r + 1, 0);
    }
  } else {
    for (int v = 1; v <= 9; v++) {
      if (check(v, r, c)) {
        graph[r][c] = v;
        maxRow[r][v] = true;
        maxCol[c][v] = true;
        markSquare[r / 3][c / 3][v] = true;
        if (r == 8 && c == 8)
          solution();
        else {
          if (c < 8)
            TRY(r, c + 1);
          else
            TRY(r + 1, 0);
        }
        maxRow[r][v] = false;
        maxCol[c][v] = false;
        markSquare[r / 3][c / 3][v] = false;
        graph[r][c] = 0;
      }
    }
  }
}

int main(int argc, char *argv[]) {
  for (int v = 1; v <= 9; v++) {
    for (int r = 0; r < 9; r++)
      maxRow[r][v] = false;
    for (int c = 0; c < 9; c++)
      maxCol[c][v] = false;
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
        markSquare[i][j][v] = false;
      }
    }
  }
  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      int x;
      cin >> x;
      graph[i][j] = x;
      maxRow[i][x] = true;
      maxCol[j][x] = true;
      markSquare[i / 3][j / 3][x] = true;
    }
  }
  cout << endl;
  TRY(0, 0);
  return 0;
}
