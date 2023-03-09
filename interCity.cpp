#include <bits/stdc++.h>
#define INF 1000000000
#define N 5001
#define M 10001

using namespace std;

int n, m;
int C[N], D[M];
vector<int> a[N];
vector<pair<int,int>> g[N];
bool visited[N];
int dist[N];
int previous[N];

void input() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    scanf("%d %d", &C[i], &D[i]);
  }
  for (int i = 1; i <= m; i++) {
    int x, y;
    scanf("%d %d", &x, &y);
    a[x].push_back(y);
    a[y].push_back(x);
  }
}

void bfs(int start) {
  queue<pair<int,int>> q; // node, distance
  q.push(make_pair(start, 0));
  visited[start] = true;
  while (!q.empty()) {
    int u = q.front().first;
    int d = q.front().second;
    q.pop();
    for (int i = 0; i < a[u].size(); i++) {
      int v = a[u][i];
      if (visited[v] == false && (d + 1) <= D[start]) {
        q.push(make_pair(v, d+1));
        visited[v] = true;
        g[start].push_back(make_pair(v, C[start]));
      }
    }
  }
}

void printGraph() {
  for (int i = 1; i <= n; i++) {
    cout << i << ": ";
    for (int j = 0; j < g[i].size(); j++) {
      cout << "(" << g[i][j].first << ", " << g[i][j].second << ") ";
    }
    cout << endl;
  }
}

void buildTree() {
  for (int i = 1; i <= n; i++) {
    memset(visited, false, sizeof(visited));
    bfs(i);
  }
  // printGraph();
}

void solve() {
  buildTree();

  for (int i = 1; i <= n; i++) {
    dist[i] = INF;
    previous[i] = -1;
  }

  priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

  pq.push(make_pair(0, 1)); // distance, node
  dist[1] = 0;
  while (!pq.empty()) {
    int u = pq.top().second;
    int d = pq.top().first;
    pq.pop();
    for (int i = 0; i < g[u].size(); i++) {
      int v = g[u][i].first;
      int w = g[u][i].second;
      if (dist[v] > dist[u] + w) {
        dist[v] = dist[u] + w;
        previous[v] = u;
        pq.push(make_pair(dist[v], v));
      }
    }
  }

  cout << dist[n] << endl;
}

int main(int argc, char const *argv[]) {
  input();
  solve();
  return 0;
}
