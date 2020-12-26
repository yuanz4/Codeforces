#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	int test;
	cin >> test;
	while (test--) {
		ll n, W;
		cin >> n >> W;
		int temp;
		vector<pair<int, int>> v;
		for (int i = 0; i < n; i++) {
			cin >> temp;
			v.push_back({temp, i+1});
		}
		sort(v.begin(), v.end());
		vector<int> ans;
		ll sum = 0;
		for (int i = n-1; i >= 0; i--) {
			ll cur = sum + v[i].first;
			if (cur <= W && 2 * cur >= W) {
				ans.push_back(v[i].second);
				sum = cur;
				break;
			}
			if (cur > W)
				continue;
			ans.push_back(v[i].second);
			sum = cur;
		}
		if (ans.empty() || 2 * sum < W || sum > W)
			cout << -1 << '\n';
		else {
			cout << ans.size() << '\n';
			for (auto& i: ans)
				cout << i << ' ';
			cout << '\n';
		}
	}
	return 0;
}