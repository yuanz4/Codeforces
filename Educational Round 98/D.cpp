#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int mod = 998244353;

ll powmod(ll a, ll b) {
	ll res = 1;
	a %= mod;
	for (; b; b >>= 1) {
		if (b & 1)
			res = res * a % mod;
		a = a * a % mod;
	}
	return res;
}

ll fraction(ll p, ll q) {
	ll inv = powmod(q, mod-2);
	return p * inv % mod;
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	int n;
	cin >> n;
	ll a[n+1];
	ll ans;
	a[0] = 1;
	a[1] = 1;
	for (int i = 2; i < n; i++)
		a[i] = (a[i-1] + a[i-2]) % mod;
	ans = a[n-1];
	cout << fraction(ans, powmod(2, n)) << '\n';
	return 0;
}