#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

vector<pii> parent, parent_ori;
vector<int> bipartite, bipartite_ori;

void build(int n) {
	parent.assign(n, pii());
	bipartite.assign(n, 1);
	for (int i = 0; i < n; i++)
		parent[i] = {i, 0};
}

pii find_set(int v) {
    if (v != parent[v].first) {
        int parity = parent[v].second;
        parent[v] = find_set(parent[v].first);
        parent[v].second ^= parity;
    }
    return parent[v];
}

void add_edge(int a, int b) {
    pii pa = find_set(a);
    a = pa.first;
    int x = pa.second;

    pii pb = find_set(b);
    b = pb.first;
    int y = pb.second;

    if (a == b) {
        if (x == y)
            bipartite[a] = false;
    } else {
        parent[b] = {a, x^y^1};
        bipartite[a] &= bipartite[b];
    }
}

bool is_bipartite(int v) {
    return bipartite[find_set(v).first];
}

void copy(int v) {
    parent[v] = parent_ori[v];
	bipartite[v] = bipartite_ori[v];
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	int n, m, k;
	cin >> n >> m >> k;
	build(n);
	int c[n];
	map<int, vector<int>> ver;
	for (int i = 0; i < n; i++) {
		cin >> c[i];
		c[i]--;
		ver[c[i]].push_back(i);
	}
	int u, v;
	int tot = 0;
	map<pii, int> neighbor;
	vector<vector<pii>> edge(m);

	for (int i = 0; i < m; i++) {
		cin >> u >> v;
		u--, v--;
		if (c[u] == c[v])
			add_edge(u, v);
		else {
			if (c[u] > c[v])
				swap(u, v);
			pii cur = {c[u], c[v]};
			if (!neighbor.count(cur))
				neighbor[cur] = tot++;
			edge[neighbor[cur]].push_back({u, v});
		}
	}
	int good = k;
	bool bad[k] = {};
	for (auto& i: ver) {
		for (auto& j: i.second) {
			if (!is_bipartite(j)) {
				bad[i.first] = true;
				good--;
				break;
			}
		}
	}
	ll ans = 1ll * good * (good - 1) / 2;
	parent_ori = parent;
	bipartite_ori = bipartite;
	for (auto& nei: neighbor) {
		int g1 = nei.first.first;
		int g2 = nei.first.second;
		if (bad[g1] || bad[g2])
			continue;
		for (auto& e: edge[nei.second]) {
			int u = e.first, v = e.second;
			copy(u);
			copy(v);
			copy(parent[u].first);
			copy(parent[v].first);
		}
		for (auto& e: edge[nei.second]) {
			int u = e.first, v = e.second;
			add_edge(u, v);
			if (!is_bipartite(u)) {
				ans--;
				break;
			}
		}
	}
	cout << ans << '\n';
	return 0;
}