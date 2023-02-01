#include <iostream>
#include <set>

using namespace std;

int n;
int d[100][100];

void input() { cin >> n; }

int selectNearest(int current, set<int> C) {
  int selectPoint;
  int nearest = 0;
  for (set<int>::iterator i = C.begin(); i != C.end(); i++) {
    if (d[current][*i] < nearest)
      selectPoint = *i;
  }
  return selectPoint;
}

void greedy() {
  int current = 1;
  set<int> C;
  for (int i = 2; i <= n; i++)
    C.insert(i);
  for (int i = 2; i <= n; i++) {
    int next = selectNearest(current);
    C.erase(next);
    route.push_back(next);
    current = next;
  }
  route.push_back(1);
  int distance = 0;
  for (int i = 0; i < route.size(); i++) {
  }
}

int main(int argc, char *argv[]) { return 0; }
