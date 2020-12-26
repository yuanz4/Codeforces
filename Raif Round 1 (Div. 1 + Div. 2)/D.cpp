#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; i++)
		cin >> a[i];
	vector<set<int>> v(4, set<int>());
	for (int i = 0; i < n; i++)
		v[a[i]].insert(i+1);
	vector<pair<int, int>> ans;
	if (!v[2].empty()) {
		for (auto& i: v[2]) {
			auto it = v[1].lower_bound(i);
			if (it == v[1].end()) {
				cout << -1 << '\n';
				return 0;
			}
			ans.push_back({i, i});
			ans.push_back({i, *it});
			v[1].erase(it);
		}
	}
	if (!v[3].empty()) {
		int last = *(prev(v[3].end()));
		int index = -1;
		if (!v[2].empty()) {
			int it = *(prev(v[2].end()));
			if (it > last)
				index = it;
		}
		if (!v[1].empty()) {
			int it = *(prev(v[1].end()));
			if (it > last)
				index = it;
		}
		if (index == -1) {
			cout << -1 << '\n';
			return 0;
		}
		ans.push_back({last, last});
		ans.push_back({last, index});
		auto it = v[3].begin();
		while (it != prev(v[3].end())) {
			ans.push_back({*it, *it});
			ans.push_back({*it, *(++it)});
		}
	}
	if (!v[1].empty()) {
		for (auto& i: v[1])
			ans.push_back({i, i});
	}
	cout << ans.size() << '\n';
	for (auto& i: ans)
		cout << i.first << " " << i.second << '\n';
	return 0;
}