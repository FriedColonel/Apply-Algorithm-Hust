#include <bits/stdc++.h>
#define MAX 11
#define INF 1000000000

using namespace std;

int n;
int graph[2*MAX + 1][2*MAX + 1];
int Tgraph[2*MAX + 1][2*MAX + 1];
int result = 0;
array<int, 2*MAX + 1> p;
array<int, 2*MAX + 1> d;
bool visited[2*MAX + 1];

void input() {
  cin >> n;
  for (int i = 0; i < 2*n + 1; i++) {
    for (int j = 0; j < 2*n + 1; j++) {
      scanf("%d", &graph[i][j]);
    }
  }
}

int findMin() {
  int m = MAX;
  int index = 0;
  for (int i = 0; i < 2*n + 1; i++) {
    if (d[i] < m && d[i] != 0 && !visited[i]) {
      m = d[i];
      index = i;
    }
  }
  return index;
}

bool findPath(int start, int end, int traverse) {
  int i = p[end];
  while (p[i] != -1) {
    if (i == traverse) {
      return true;
    }
    i = p[i];
  }
  return false;
}

void deletePath(int start, int end) {
  while(p[end] != -1) {
    Tgraph[p[end]][end] = 0;
    end = p[end];
  }
}

// dijkstra algorithm using priority queue
void dijkstra(int end) {
  for (int i = 0; i < 2*n + 1; i++) {
    d[i] = INF;
    p[i] = -1;
  }
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
  d[0] = 0;
  for (int i = 0; i < 2*n + 1; i++) {
    if (Tgraph[0][i] != 0) {
      d[i] = Tgraph[0][i];
      p[i] = 0;
      pq.push(make_pair(d[i], i));
    }
  }
  while (!pq.empty()) {
    int u = pq.top().second;
    pq.pop();
    if (u == end) break;
    for (int v = 0; v < 2*n + 1; v++) {
      if (Tgraph[u][v] != 0 && d[v] > d[u] + Tgraph[u][v]) {
        d[v] = d[u] + Tgraph[u][v];
        p[v] = u;
        pq.push(make_pair(d[v], v));
      }
    }
  }
}

void printPath(int start, int end) {
  cout << end << " ";
  if (p[end] != -1) {
    printPath(start, p[end]);
  }
}

void solve() {
  for (int i = 1; i <= n; i++) {
    memcpy (Tgraph, graph, 23*23*sizeof(int));
    dijkstra(i+n);
    while (!findPath(0, i+n, i)) {
      deletePath(0, i+n);
      dijkstra(i+n);
    }
    result += d[i+n];
  }
  cout << result << endl;
}

int main(int argc, char const *argv[]) {
  input();
  solve();
  return 0;
}
