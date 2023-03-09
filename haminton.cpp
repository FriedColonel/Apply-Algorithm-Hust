#include <bits/stdc++.h>

using namespace std;

int nbTest;
int n[100000], m[100000];
vector<int> a[100000][100000];
int visited[100000];

void input() {
  cin >> nbTest;
  for (int i = 0; i < nbTest; i++) {
    cin >> n[i] >> m[i];
    for (int j = 0; j < m[i]; i++) {
      int x, y;
      scanf("%d%d", &x, &y);
      a[i][x].push_back(y);
      a[i][y].push_back(x);
    }
  }
}



void solve() {

}

int main(int argc, char const *argv[]) {

  return 0;
}
