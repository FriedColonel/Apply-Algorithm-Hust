#include <bits/stdc++.h>
#define N 1000001

using namespace std;

int a[N];
int n;
int SC[N];
bool BC[N];
int SL[N];
bool BL[N];
int ans;

void input() {
	cin >> n;
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
}

void solve() {
	if (a[1] % 2 == 0) {
		SC[1] = a[1]; BC[1] = true;
		BL[1] = false;
	} else {
		SL[1] = a[1]; BL[1] = true;
		BC[1] = false;
	}
	for (int i = 2; i <= n; i++) {
		if (abs(a[i]) % 2 == 0) {
			if (BC[i-1] && SC[i-1] > 0) {
				SC[i] = SC[i-1] + a[i];
			} else {
				SC[i] = a[i];
			}
			BC[i] = true;
			if (BL[i-1]) {
				SL[i] = SL[i - 1] + a[i];
				BL[i] = true;
			} else {
				BL[i] = false;
			}
		} else {
			if (BL[i-1]) {
				SC[i] = SL[i-1] + a[i];
				BC[i] = true;
			} else BC[i] = false;
			if (BC[i-1] && SC[i-1] > 0) {
				SL[i] = SC[i-1] + a[i];
				BL[i] = true;
			} else {
				SL[i] = a[i];
				BL[i] = true;
			}
		}
	}
	ans = *max_element(SC+1, SC+n+1);
}

int main(int argc, char const *argv[]) {
	input();
	solve();
	cout << ans;
	return 0;
}
