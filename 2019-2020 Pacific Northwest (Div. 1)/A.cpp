#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n;
vector<int> t;
vector<vector<pair<int, int>>> adj;
ll a0, b0;
vector<ll> tax, size, ans;

void initialize(int u, int p, ll dist) {
	size[u] = 1;
	tax[u] = t[u];
	for (auto& i: adj[u]) {
		int v = i.first;
		int w = i.second;
		if (v != p) {
			initialize(v, u, dist + w);
			size[u] += size[v];
			tax[u] += tax[v];
		}
	}
	a0 += dist;
	b0 += t[u] * dist;
}

void dfs(int u, int p, ll a, ll b) {
	ans[u] = t[u] * a + b;
	for (auto& i: adj[u]) {
		int v = i.first;
		int w = i.second;
		if (v != p) {
			ll av = a + w * ((n - size[v]) - size[v]);  
			ll bv = b + w * ((tax[0] - tax[v]) - tax[v]);
			dfs(v, u, av, bv);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	cin >> n;
	t.resize(n);
	tax.resize(n);
	size.resize(n);
	adj.resize(n);
	ans.resize(n);
	for (int i = 0; i < n; i++)
		cin >> t[i];
	int u, v, w;
	for (int i = 0; i < n - 1; i++) {
		cin >> u >> v >> w;
		u--;
		v--;
		adj[u].push_back({v, w});
		adj[v].push_back({u, w});
	}
	initialize(0, 0, 0);
	dfs(0, 0, a0, b0);
	for (auto& i: ans)
		cout << i << '\n';
	return 0;
}