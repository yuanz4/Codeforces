#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	int a[6];
	for (int i = 0; i < 6; i++)
		cin >> a[i];
	int n;
	cin >> n;
	int b[n];
	for (int i = 0; i < n; i++)
		cin >> b[i];
	vector<pair<int, int>> v;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 6; j++) {
			if (b[i] - a[j] >= 1)
				v.push_back({b[i]-a[j], i});
		}
	}
	sort(v.begin(), v.end());
	unordered_map<int, int> freq;
	int left = 0, right = 0;
	int ans = INT_MAX;
	while (right < v.size()) {
		if (freq.size() != n) {
			freq[v[right].second]++;
			right++;
		}
		while (freq.size() == n) {
			ans = min(ans, v[right-1].first-v[left].first);
			int cur = v[left++].second;
			freq[cur]--;
			if (freq[cur] == 0)
				freq.erase(cur);
		}
	}
	cout << ans << '\n';
	return 0;
}