#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
vector<vector<int>> adj;
vector<int> a;

struct info {
	ll large, sum, n;
	info(ll large, ll sum, ll n) : large(large), sum(sum), n(n){}
};

info dfs(int i) {
	if (adj[i].empty())
		return info(a[i], a[i], 1);
	ll large = 0, sum = 0, n = 0;
	for (auto& j: adj[i]) {
		info ret = dfs(j);
		sum += ret.sum;
		n += ret.n;
		large = max(large, ret.large);
	}
	ll left = a[i];
	if (left > large*n-sum) {
		left -= large*n-sum;
		sum = n * large;
		ll add = left / n;
		large += add;
		if (left % n != 0)
			large += 1;
	}
	sum += left;
	return info(large, sum, n);
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	int n;
	cin >> n;
	adj = vector<vector<int>>(n+1, vector<int>());
	int p;
	for (int i = 2; i <= n; i++) {
		cin >> p;
		adj[p].push_back(i);
	}
	a = vector<int>(n+1);
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	info ret = dfs(1);
	cout << ret.large << '\n';
	return 0;
}