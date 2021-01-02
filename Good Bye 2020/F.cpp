#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll mod = 1e9+7;

vector<int> p;
// Initially we count edges in subgraph for k = 2,
// when some point is k = 1, we upgrade this
// connected subgraph to count vertices
// Record whether a subgraph upgraded in root vertex
vector<bool> upgrade;

int get(int x) {
	if (p[x] == x)
		return x;
	return p[x] = get(p[x]);
}

bool merge(int x, int y) {
	x = get(x);
	y = get(y);
	// Connect two subgraph
	p[y] = x;
	// If both subgraph upgraded, don't add basis
	if (upgrade[x] && upgrade[y])
		return false;
	// If any of subgraph is upgraded, then
	// the merged subgraph is also upgraded
	upgrade[x] = upgrade[x] | upgrade[y];
	// If both of them already in same subgraph,
	// don't add basis
	return x != y;
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	int n, m;
	cin >> n >> m;
	p.resize(m);
	upgrade.assign(m, false);
	for (int i = 0; i < m; i++)
		p[i] = i;
	int k, u, v;
	// The number of vector basis
	vector<int> ans;
	for (int i = 0; i < n; i++) {
		cin >> k >> u;
		u--;
		if (k > 1) {
			cin >> v;
			v--;
			// Decide whether to add new basis
			if (merge(u, v))
				ans.push_back(i+1);
		} else {
			u = get(u);
			// Upgrade the subgraph containing u,
			// if already upgraded, then u is redundant
			if (!upgrade[u]) {
				ans.push_back(i+1);
				upgrade[u] = true;
			}
		}
	}
	ll res = 1;
	for (int i = 0; i < ans.size(); i++)
		res = (res * 2) % mod;
	cout << res << " " << ans.size() << '\n';
	for (auto& i: ans)
		cout << i << ' ';
	cout << '\n';
	return 0;
}