#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	int test;
	cin >> test;
	while (test--) {
		ll n, k;
		cin >> n >> k;
		ll l1, r1, l2, r2;
		cin >> l1 >> r1 >> l2 >> r2;
		ll inter = min(r1, r2) - max(l1, l2);
		ll full = max(r1, r2) - min(l1, l2);
		ll ans = 1e18;
		if (inter >= 0) {
			ll remain = k - inter * n;
			ll extend = full - abs(inter);
			if (remain <= 0)
				ans = 0;
			else if (n * extend >= remain)
				ans = remain;
			else
				ans = extend * n + 2 * (remain - extend * n);
		} else {
			ll gap = -inter;
			for (int i = 1; i <= n; i++) {
				ll cur = i * gap;
				if (i * full >= k)
					cur += k;
				else
					cur += i * full + 2 * (k - i * full);
				ans = min(ans, cur);
			}
		}
		cout << ans << '\n';
	}
	return 0;
}