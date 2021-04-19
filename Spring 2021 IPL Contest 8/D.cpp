#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	int n[4], m[4];
	vector<pair<int, int>> a[4];
	unordered_map<int, unordered_set<int>> bad[3];
	for (int i = 0; i < 4; i++)
		cin >> n[i];
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < n[i]; j++) {
			int cur;
			cin >> cur;
			a[i].push_back({cur, j});
		}
	}
	for (int i = 0; i < 3; i++) {
		cin >> m[i];
		for (int j = 0; j < m[i]; j++) {
			int x, y;
			cin >> x >> y;
			x--, y--;
			bad[i][y].insert(x);
		}
	}
	for (int i = 1; i < 4; i++) {
		sort(a[i-1].begin(), a[i-1].end());
		for (int j = 0; j < n[i]; j++) {
			int val = a[i][j].first;
			int index = a[i][j].second;
			a[i][j].first = INT_MAX;
			for (int k = 0; k < n[i-1]; k++) {
				if (bad[i-1][index].count(a[i-1][k].second))
					continue;
				if (a[i-1][k].first != INT_MAX)
					a[i][j].first = val + a[i-1][k].first;
				break;
			}
		}
	}
	int ans = min_element(a[3].begin(), a[3].end())->first;
	if (ans == INT_MAX)
		cout << -1 << '\n';
	else
		cout << ans << '\n';
	return 0;
}