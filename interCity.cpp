#include <bits/stdc++.h>
#define N 5002
#define M 10002

using namespace std;

struct Edge {
  int u, v;
  Edge(int _u, int _v) {
    this->u = _u;
    this->v = _v;
  }
};

int n, m;
int c[N], d[M];
int I, J;
vector<int> graph[N];
vector<pair<int,int>> Tgraph[N];
int parent[N];
int dist[N];
int weight[N];

void input() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    scanf("%d%d", &c[i], &d[i]);
  }
  for (int i = 0; i < m; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    graph[u].push_back(v);
    graph[v].push_back(u);
  }
}

void bfs(int u, int c, int d) {
  queue<int> q;
  q.push(u);
  weight[u] = 0;
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (int i = 0; i < graph[u].size(); i++) {
      int v = graph[u][i];
      weight[v] = weight[u] + 1;
      if (weight[v] > d) return;
      Tgraph[u].push_back(make_pair(v, c));
      q.push(v);
    }
  }
}

void dijikstra() {
  priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
  pq.push(make_pair(0, I));
  dist[I] = 0;
  while (!pq.empty()) {
    int u = pq.top().second;
    pq.pop();
    for (int i = 0; i < Tgraph[u].size(); i++) {
      int v = Tgraph[u][i].first;
      int w = Tgraph[u][i].second;
      if (dist[v] > dist[u] + w) {
        dist[v] = dist[u] + w;
        pq.push(make_pair(dist[v], v));
      }
    }
  }
}

void solve() {

}

int main(int argc, char const *argv[]){
  return 0;
}
