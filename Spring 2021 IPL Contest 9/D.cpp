#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	int n, m;
	cin >> n >> m;
	vector<vector<pair<int, int>>> adj(n);
	int sum = 0;
	for (int i = 0; i < m; i++) {
		int u, v, e;
		cin >> u >> v >> e;
		u--, v--;
		adj[u].push_back({v, e});
		adj[v].push_back({u, e});
		sum ^= e;
	}
	cout << bitset<8>(sum) << '\n';
	return 0;
}