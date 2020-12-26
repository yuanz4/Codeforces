#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll mod = 998244353;
const ll MAX = 2e5+7;

ll mul(ll a, ll b) {
	return a * b % mod;
}

ll powmod(ll a, ll b) {
	a %= mod;
	ll ans = 1;
	for (; b; b >>= 1) {
		if (b & 1)
			ans = mul(ans, a);
		a = mul(a, a);
	}
	return ans;
}

ll inv(ll a) {
	return powmod(a, mod-2);
}

ll d[MAX], pre[MAX];

ll sum(int l, int r) {
	return (pre[r] - pre[l]) % mod;
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> d[i];
	sort(d, d+n);
	for (int i = 0; i < n; i++)
		pre[i+1] = pre[i] + d[i];
	int a, b;
	while (m--) {
		cin >> a >> b;
		int strong = d + n - lower_bound(d, d+n, b);
		ll ans = 0;
		if (strong >= a) {
			ans += mul(mul(sum(n-strong, n), strong-a), inv(strong));
			ans += mul(mul(sum(0, n-strong), strong-a+1), inv(strong+1));
			ans %= mod;
		}
		cout << ans << '\n';
	}
	return 0;
}