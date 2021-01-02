#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll mod = 1e9+7;

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	int test;
	cin >> test;
	while (test--) {
		int n;
		cin >> n;
		ll a[n];
		int mx = 60;
		ll bit[mx] = {};
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			for (int j = 0; j < mx; j++)
				bit[j] += (a[i] >> j) & 1;
		}
		ll ans = 0;
		for (int i = 0; i < n; i++) {
			ll left = 0, right = 0;
			for (int j = 0; j < mx; j++) {
				if ((a[i] >> j) & 1) {
					left = ((((1ll << j) % mod) * bit[j]) % mod + left) % mod;
					right = ((((1ll << j) % mod) * n) % mod + right) % mod;
				} else
					right = ((((1ll << j) % mod) * bit[j]) % mod + right) % mod;
			}
			ans = ((left * right) % mod + ans) % mod;
		}
		cout << ans << '\n';
	}
	return 0;
}