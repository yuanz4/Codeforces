#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	int n;
	cin >> n;
	int u, v, p;
	vector<vector<int>> adj(n);
	ll ans = 0;
	for (int i = 0; i < n - 1; i++) {
		cin >> u >> v >> p;
		adj[u].push_back(p);
		adj[v].push_back(p);
		ans += p;
	}
	for (int u = 0; u < n; u++) {
		ll sum = 0;
		int mx = 0;
		for (auto& v: adj[u]) {
			mx = max(mx, v);
			sum += v;
		}
		if (mx > sum - mx)
			ans -= sum - mx;
		else
			ans -= sum / 2;
	}
	cout << ans << '\n';
	return 0;
}