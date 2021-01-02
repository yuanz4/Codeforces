#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	int test;
	cin >> test;
	while (test--) {
		int n;
		cin >> n;
		int w[n];
		ll sum = 0;
		for (int i = 0; i < n; i++) {
			cin >> w[i];
			sum += w[i];
		}
		int u, v;
		int d[n] = {};
		for (int i = 0; i < n-1; i++) {
			cin >> u >> v;
			u--;
			v--;
			d[u]++;
			d[v]++;
		}
		priority_queue<pair<int, int>> pq;
		for (int i = 0; i < n; i++) {
			if (d[i] > 1)
				pq.push({w[i], i});
		}
		vector<ll> ans = {sum};
		for (int i = 0; i < n-2; i++) {
			pair<int, int> cur = pq.top();
			pq.pop();
			ans.push_back(ans.back() + cur.first);
			d[cur.second]--;
			if (d[cur.second] > 1)
				pq.push(cur);
		}
		for (auto& i: ans)
			cout << i << ' ';
		cout << '\n';
	}
	return 0;
}