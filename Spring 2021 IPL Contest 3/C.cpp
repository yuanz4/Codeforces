#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, m;
vector<vector<int>> adj;
vector<vector<int>> d;

void dfs(int u, int p) {
	d[u][0] = 0;
	d[u][1] = 1;
	for (auto& v: adj[u]) {
		if (v != p) {
			dfs(v, u);
			d[u][0] += d[v][1];
			d[u][1] += min(d[v][0], d[v][1]);
		}
	}
} 

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	cin >> n >> m;
	adj.resize(n + m);
	d.assign(n + m, vector<int>(2, INT_MAX));
	int u, v;
	for (int i = 0; i < n + m; i++) {
		cin >> u >> v;
		if (u < n && v < n)
			continue;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for (int i = 0; i < n; i++)
		dfs(i, -1);
	int ans = INT_MAX;
	vector<vector<int>> first(n, vector<int>(2, INT_MAX / 2));
	auto second = first;
	first[0][0] = d[0][0];
	for (int i = 1; i < n; i++) {
		first[i][0] = first[i-1][1] + d[i][0];
		first[i][1] = min(first[i-1][0], first[i-1][1]) + d[i][1];
	}
	ans = min(ans, first[n-1][1]);
	second[0][1] = d[0][1];
	for (int i = 1; i < n; i++) {
		second[i][0] = second[i-1][1] + d[i][0];
		second[i][1] = min(second[i-1][0], second[i-1][1]) + d[i][1];
	}
	ans = min({ans, second[n-1][0], second[n-1][1]});
	cout << ans << '\n';
	return 0;
}