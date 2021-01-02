#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll mod = 1e9+7;

vector<int> p;

int get(int x) {
	if (p[x] == x)
		return x;
	return p[x] = get(p[x]);
}

bool merge(int x, int y) {
	x = get(x);
	y = get(y);
	p[y] = x;
	return x != y;
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	int n, m;
	cin >> n >> m;
	p.resize(m+1);
	for (int i = 0; i <= m; i++)
		p[i] = i;
	int k, u, v;
	vector<int> ans;
	for (int i = 0; i < n; i++) {
		cin >> k >> u;
		u--;
		if (k > 1) {
			cin >> v;
			v--;
		} else
			v = m;
		if (merge(u, v))
			ans.push_back(i+1);
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