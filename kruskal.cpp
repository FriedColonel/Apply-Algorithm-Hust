#include <bits/stdc++.h>
#define N 100001

using namespace std;

struct Edge {
  int u, v, w;
  Edge(int _u, int _v, int _w) {
    this->u = _u;
    this->v = _v;
    this->w = _w;
  }
};

int n, m;
vector<Edge> edges;
int W = 0;
int p[N], r[N];

void input() {
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int u, v, w;
    scanf("%d%d%d", &u, &v, &w);
    edges.push_back(Edge(u,v,w));
  }
}

bool compare(Edge e1, Edge e2) {
  return e1.w < e2.w;
}

int findParents(int u) {
  if (p[u] == u) return u;
  p[u] = findParents(p[u]);
  return p[u];
}

void unify(int x, int y) {
  if (r[x] > r[y]) {
    p[y] = x;
  } else {
    p[x] = y;
    if (r[x] == r[y]) {
      r[y]++;
    }
  }
}

void makeSet(int x) {
  p[x] = x;
  r[x] = 0;
}

void solve() {
  sort(edges.begin(), edges.end(), compare);
  vector<Edge> TE;
  for (int i = 0; i < n; i++) {
    makeSet(i);
  }
  for (Edge e: edges) {
    int ru = findParents(e.u);
    int rv = findParents(e.v);
    if (ru != rv) {
      unify(ru, rv);
      TE.push_back(e);
      W += e.w;
    }
  }
  cout << W;
}

int main(int argc, char const *argv[]) {
  input();
  solve();
  return 0;
}
