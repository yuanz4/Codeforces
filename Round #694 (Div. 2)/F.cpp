#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<vector<int>> adj;
vector<int> ans, color;
unordered_set<int> visited;

// 1 for black, 2 for white
void dfs(int node, int c) {
	if (visited.count(node))
		return;
	visited.insert(node);
	if (c == 1) {
		color[node] = 1;
		ans.push_back(node);
		for (auto& i: adj[node])
			color[i] = 2;
		for (auto& i: adj[node])
			dfs(i, 2);
	} else {
		for (auto& i: adj[node]) {
			if (!color[i])
				dfs(i, 1);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	int test;
	cin >> test;
	while (test--) {
		int n, m;
		cin >> n >> m;
		int u, v;
		adj.assign(n, vector<int>());
		color.assign(n, 0);
		ans.clear();
		visited.clear();
		for (int i = 0; i < m; i++) {
			cin >> u >> v;
			u--, v--;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		dfs(0, 1);
		if (visited.size() != n)
			cout << "NO" << '\n';
		else {
			cout << "YES" << '\n';
			cout << ans.size() << '\n';
			for (auto& i: ans)
				cout << i + 1 << ' ';
			cout << '\n';
		}
	}
	return 0;
}