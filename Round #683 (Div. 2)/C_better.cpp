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
		ll cur;
		ll sum = 0;
		vector<int> ans;
		bool ok = false;
		for (int i = 0; i < n; i++) {
			cin >> cur;
			if (ok)
				continue;
			if (cur <= W && cur >= (W+1)/2) {
				ans.clear();
				ans.push_back(i+1);
				sum = cur;
				ok = true;
			} else if (cur > W)
				continue;
			else {
				sum += cur;
				ans.push_back(i+1);
				if (sum <= W && sum >= (W+1)/2)
					ok = true;
			}
		}
		if (ans.empty() || sum < (W+1)/2 || sum > W)
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