#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	int n, m;
	cin >> n >> m;
	vector<vector<pair<int, int>>> adj(n*51);
	auto add = [&](int u, int v, int w) {
		adj[51*u].push_back({51*v+w, 0});
		for (int was = 1; was <= 50; was++)
			adj[51*u+was].push_back({51*v, (was+w)*(was+w)});
	};
	int u, v, w;
	for (int i = 0; i < m; i++) {
		cin >> u >> v >> w;
		u--, v--;
		add(u, v, w);
		add(v, u, w);
	}
	vector<int> d(n*51, INT_MAX);
	d[0] = 0;
	set<pii> pq;
	pq.insert({0, 0});
	while (!pq.empty()) {
		auto it = pq.begin();
		int u = it->second;
		pq.erase(it);
		for (auto& edge: adj[u]) {
			int v = edge.first;
			int len = edge.second;
			if (len + d[u] < d[v]) {
				pq.erase({d[v], v});
				d[v] = len + d[u];
				pq.insert({d[v], v});
			}
		}
	}
	for (int i = 0; i < n; i++) {
		int ans = d[i*51];
		cout << (ans == INT_MAX ? -1 : ans) << ' ';
	}
	return 0;
}