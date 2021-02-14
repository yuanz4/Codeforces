#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll ans = 0;
vector<vector<pair<int, int>>> adj;

void dfs(int u, int p, int plen) {
	ll sum = 0;
	int mx = 0;
	for (auto& i: adj[u]) {
		int v = i.first;
		if (v == p)
			continue;
		sum += i.second;
		mx = max(mx, i.second);
		dfs(v, u, i.second);
	}
	if (mx - plen > sum - mx)
		ans += mx - plen;
	else
		ans += (max(sum - plen, 0ll) + 1) / 2;
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	int n;
	cin >> n;
	adj.resize(n);
	int u, v, p;
	for (int i = 0; i < n - 1; i++) {
		cin >> u >> v >> p;
		adj[u].push_back({v, p});
		adj[v].push_back({u, p});
	}
	dfs(0, 0, 0);
	cout << ans << '\n';
	return 0;
}