#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	int n, k;
	cin >> n >> k;
	int a[n+2];
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		a[i] -= i;
	}
	a[0] = INT_MIN;
	a[n+1] = INT_MAX;
	int b[k+2];
	for (int i = 1; i <= k; i++)
		cin >> b[i];
	b[0] = 0;
	b[k+1] = n+1;
	int ans = 0;
	for (int i = 0; i <= k; i++) {
		int l = b[i], r = b[i+1];
		int left = a[b[i]];
		int right = a[b[i+1]];
		if (right < left) {
			cout << -1 << '\n';
			return 0;
		}
		vector<int> valid, v;
		for (int j = l+1; j < r; j++) {
			if (a[j] >= left && a[j] <= right)
				valid.push_back(a[j]);
		}
		for (auto& j: valid) {
			if (v.empty() || j >= v.back())
				v.push_back(j);
			else {
				auto it = upper_bound(v.begin(), v.end(), j);
				*it = j;
			}
		}
		int stable = v.size();
		ans += r - l - 1 - stable;
	}
	cout << ans << '\n';
	return 0;
}