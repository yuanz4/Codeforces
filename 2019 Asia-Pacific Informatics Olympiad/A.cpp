#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll gcd(ll a, ll b) {
	return b == 0 ? a : gcd(b, a%b);
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	int n;
	ll A, B;
	cin >> n >> A >> B;
	ll g = gcd(A, B+1);
	ll l[n], r[n];
	ll MAX = 0;
	for (int i = 0; i < n; i++) {
		cin >> l[i] >> r[i];
		MAX = max(MAX, r[i] + 1);
	}
	ll ans = 0;
	if (A / g > MAX / B) {
		for (int i = 0; i < n; i++)
			ans += r[i] - l[i] + 1;
	} else {
		ll len = A / g * B;
		vector<pair<ll, ll>> v;
		for (int i = 0; i < n; i++) {
			if (r[i] - l[i] + 1 >= len) {
				cout << len << '\n';
				return 0;
			}
			ll left = l[i] % len;
			ll right = r[i] % len;
			if (left <= right)
				v.push_back({left, right});
			else {
				v.push_back({0, right});
				v.push_back({left, len-1});
			}
		}
		sort(v.begin(), v.end());
		ll start = 0, end = -1;
		for (auto& i: v) {
			if (i.first > end) {
				ans += end - start + 1;
				start = i.first;
				end = i.second;
			} else
				end = max(end, i.second);
		}
		ans += end - start + 1;
	}
	cout << ans << '\n';
	return 0;
}