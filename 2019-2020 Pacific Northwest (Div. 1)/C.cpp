#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	int n, m;
	cin >> n >> m;
	vector<vector<int>> adj(n);
	int u, v;
	for (int i = 0; i < m; i++) {
		cin >> u >> v;
		u--, v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	vector<int> d(n, n + 1);
	d[0] = 0;
	queue<int> q;
	q.push(0);
	while (q.size()) {
		int cur = q.front();
		if (cur == n - 1)
			break;
		q.pop();
		for (auto& i: adj[cur]) {
			if (d[i] == n + 1) {
				d[i] = d[cur] + 1;
				q.push(i);
			}
		}
	}
	cout << d[n-1] - 1 << '\n';
	return 0;
}