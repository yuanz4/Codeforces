#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	int r, n;
	cin >> r >> n;
	int t[n+1], x[n+1], y[n+1];
	t[0] = 0, x[0] = 1, y[0] = 1;
	for (int i = 1; i <= n; i++)
		cin >> t[i] >> x[i] >> y[i];
	int ans[n+1] = {};
	multimap<int, int> m;
	for (int i = n; i >= 0; i--) {
		for (auto p: m) {
			int j = p.second;
			int dist = abs(x[i]-x[j]) + abs(y[i]-y[j]);
			if (t[j]-t[i] >= dist) {
				ans[i] = max(ans[i], ans[j]);
				break;
			}
		}
		ans[i]++;
		m.insert({-ans[i], i});
	}
	cout << ans[0]-1 << '\n';
	return 0;
}