#include <bits/stdc++.h>
#define N 100001

using namespace std;

int n,m;
vector<int> A[N];
int d[N];

void input() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		A[u].push_back(v);
		A[v].push_back(u);
	}
}

int BFS(int u) {
	queue<int> Q;
	for (int i = 1; i <= n; i++) d[i] = -1;
	Q.push(u);
	// visisted[u] = true;
	d[u] = 1;
	while(!Q.empty()) {
		int v = Q.front();
		Q.pop();
		for (int i = 0; i < A[v].size(); i++) {
			int k = A[v][i];
			if (d[k] == -1) {
				Q.push(k);
				d[k] = d[v] + 1;
			} else if ((d[k] % 2) == (d[v] % 2)) return 0;
		}
	}
	return 1;
}

int main(int argc, char const *argv[]) {
	input();
	cout << BFS(1);
	return 0;
}
