#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	int test;
	cin >> test;
	while (test--) {
		ll n;
		cin >> n;
		ll a[n], b[n];
		for (int i = 0; i < n; i++)
			cin >> a[i];
		for (int i = 0; i < n; i++)
			cin >> b[i];
		vector<pair<ll, ll>> v;
		for (int i = 0; i < n; i++)
			v.push_back({a[i], b[i]});
		sort(v.begin(), v.end());
		ll ans = 0;
		for (int i = n-1; i >= 0; i--) {
			if (ans + v[i].second < v[i].first)
				ans += v[i].second;
			else {
				ans = max(ans, v[i].first);
				break;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}