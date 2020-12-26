#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int k;
vector<vector<int>> adj;

int dfs(int node, int p) {
	vector<int> child;
	for (auto& i: adj[node]) {
		if (i == p)
			continue;
		child.push_back(dfs(i, node));
	}
	sort(child.begin(), child.end());
	if (child.empty())
		return 1;
	if (child.size() == 1)
		return child[0] + 1;
	int n = child.size();
	if (node == 0) {
		k = max(k, child[n-2]+1);
		return child[n-1] + 1;
	} else {
		k = max(k, child[n-1]+1);
		return child[0] + 1;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	int test;
	cin >> test;
	while (test--) {
		int n;
		cin >> n;
		int u, v;
		adj.assign(n, vector<int>());
		for (int i = 0; i < n-1; i++) {
			cin >> u >> v;
			u--, v--;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		k = 1;
		k = max(k, dfs(0, -1)-1);
		cout << k << '\n';
	}
	return 0;
}