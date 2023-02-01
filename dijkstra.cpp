#include <bits/stdc++.h>
#define pii pair<int,int>

using namespace std;

struct Arc
{
  int node;
  int w;
  Arc(int _nod, int _w) {
    node = _nod;
    w = _w;
  }
};

const unsigned int DIST_INFTY = 1e8;
const unsigned int N = 1e6;
int n, m;
vector<Arc> A[N];
int s, e;
int d[N];
int p[N];

void input() {
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    int u,v,w;
    scanf("%d%d%d", &u, &v, &w);
    A[u].push_back(Arc(v,w));
  }
  scanf("%d%d", &s, &e);
}

int selectMin(set<int>& NonFixed) {
  int minD = DIST_INFTY; int sol_v = -1;
  for (set<int>::iterator i = NonFixed.begin(); i != NonFixed.end(); i++) {
    int v = *i;
    if (d[v] < minD) {
      minD = d[v];
      sol_v = v;
    }
  }
  return sol_v;
}

void dijkstra() {
  set<int> NonFixed;
  for (int v = 1; v <= n; v++) {
    d[v] = DIST_INFTY;
    p[v] = s;
  }
  d[s] = 0;
  for (int i = 0; i < A[s].size(); i++) {
    Arc a = A[s][i];
    d[a.node] = a.w;
  }
  for (int i = 1; i <= n; i++) if (i != s) NonFixed.insert(i);
  while(!NonFixed.empty()) {
    int u = selectMin(NonFixed);
    if (u == e) break;
    NonFixed.erase(u); // shortest path from s to u has been found
    for (int i = 0; i < A[u].size(); ++i) {
      Arc a= A[u][i];
      int v = a.node;
      int w = a.w;
      if (d[v] > d[u] + w) {
        d[v] = d[u] + w;
        p[v] = u;
      }
    }
  }
  cout << d[e];
}

void dijkstraPQ() {
  priority_queue<pii, vector<pii>, greater<pii>> pq;
  for (int v = 1; v <= n; v++) {
    d[v] = DIST_INFTY;
  }
  d[s] = 0;
  for (int i = 0; i < A[s].size(); i++) {
    Arc a = A[s][i];
    d[a.node] = a.w;
    pq.push(make_pair(a.w, a.node));
  }
  while(!pq.empty()) {
    pii u = pq.top(); pq.pop();
    if (u.second == e) break;
    for (int i = 0; i < A[u.second].size(); i++) {
      Arc a = A[u.second][i];
      int v = a.node;
      int w = a.w;
      if (d[v] > d[u.second] + w) {
        d[v] = d[u.second] + w;
        p[v] = u.second;
        pq.push(make_pair(d[v], v));
      }
    }
  }
  cout << d[e];
}

int main(int argc, char const *argv[]) {
  input();
  // dijkstra();
  dijkstraPQ();
  return 0;
}
