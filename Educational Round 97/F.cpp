#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int mod = 998244353;
const int mx = 5000+7;
int a[mx];
ll d[mx][mx];
ll pre[mx][mx];
int cntLess[mx];
int lastLess[mx];

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	sort(a, a+n);
	for (int i = 0; i < n; i++) {
		d[i][1] = 1;
		pre[i+1][1] = pre[i][1] + 1;
	}
	for (int i = 0; i < n; i++) {
		lastLess[i] = -1;
		for (int j = 0; j < i; j++) {
			if (a[j] * 2 <= a[i]) {
				cntLess[i]++;
				lastLess[i] = j;
			}
		}
	}
	for (int j = 2; j <= n; j++) {
		for (int i = 0; i < n; i++) {
			d[i][j] = pre[lastLess[i]+1][j-1];
			if (cntLess[i]-j+2 >= 1)
				d[i][j] = (d[i][j] + d[i][j-1] * (cntLess[i]-j+2)) % mod;
			pre[i+1][j] = (pre[i][j] + d[i][j]) % mod;
		}
	}
	cout << d[n-1][n] << '\n';
	return 0;
}