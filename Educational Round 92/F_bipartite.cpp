#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	int n;
	cin >> n;
	int l[n], r[n], t[n];
	for (int i = 0; i < n; i++) {
		cin >> l[i] >> r[i] >> t[i];
		t[i]--;
	}
	vector<pair<int, pii>> event;
	for (int i = 0; i < n; i++) {
		event.push_back({l[i], {0, i}});
		event.push_back({r[i], {1, i}});
	}
	sort(event.begin(), event.end());
	set<pii> end[2];
	int ans = 0;
	for (auto& e: event) {
		int i = e.second.second;
		int color = t[i];
		pii right = {r[i], i};
		if (e.second.first) {
			int op_color = color ^ 1;
			if (end[color].count(right) && !end[op_color].empty()) {
				ans++;
				end[op_color].erase(end[op_color].begin());
			}
			if (end[color].count(right))
				end[color].erase(right);
		} else
			end[color].insert(right);
	}
	cout << n - ans << '\n';
	return 0;
}