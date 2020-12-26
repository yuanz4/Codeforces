#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int mx = 207;
int d[mx][mx];

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	int n, m;
	cin >> n >> m;
	int u[m], v[m], b[m];
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i != j)
				d[i][j] = INT_MAX;
		}
	}
	for (int i = 0; i < m; i++) {
		cin >> u[i] >> v[i] >> b[i];
		d[u[i]][v[i]] = 1;
		d[v[i]][u[i]] = b[i] ? -1 : 1;
	}
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (d[i][k] != INT_MAX && d[k][j] != INT_MAX)
					d[i][j] = min(d[i][j], d[i][k]+d[k][j]);
			}
		}
	}
	pair<int, int> best = {-1, 1};
	for (int i = 1; i <= n; i++) {
		if (d[i][i] < 0) {
			cout << "NO" << '\n';
			return 0;
		}
		for (int j = 1; j <= n; j++)
			best = max(best, {d[i][j], i});
	}
	int s = best.second;
	for (int i = 0; i < m; i++) {
		if ((d[s][u[i]] + d[s][v[i]]) % 2 == 0) {
			cout << "NO" << '\n';
			return 0;
		}
	}
	cout << "YES" << '\n';
	cout << best.first << '\n';
	for (int i = 1; i <= n; i++)
		cout << d[s][i] << ' ';
	cout << '\n';
	return 0;
}