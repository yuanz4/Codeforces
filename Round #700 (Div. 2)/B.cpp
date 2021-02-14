#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	int test;
	cin >> test;
	while (test--) {
		ll A, B, n;
		cin >> A >> B >> n;
		int a[n], b[n];
		for (int i = 0; i < n; i++)
			cin >> a[i];
		for (int i = 0; i < n; i++)
			cin >> b[i];
		vector<pair<int, int>> mon;
		for (int i = 0; i < n; i++)
			mon.push_back({a[i], b[i]});
		sort(mon.begin(), mon.end());
		ll damage = 0;
		for (int i = 0; i < n; i++) {
			damage += (mon[i].second + A - 1) / A * mon[i].first;
			if (i == n - 1)
				damage -= mon[i].first;
		}
		if (damage >= B)
			cout << "NO" << '\n';
		else
			cout << "YES" << '\n';
	}
	return 0;
}