#include <bits/stdc++.h>
using namespace std;

int mod = 998244353;

int add(int a, int b) {
	a += b;
	if (a >= mod)
		a -= mod;
	if (a < 0)
		a += mod;
	return a;
}

int mul(int a, int b) {
	return 1ll * a * b % mod;
}

int powmod(int a, int b) {
	int res = 1;
	for (; b; b >>= 1) {
		if (b & 1)
			res = mul(res, a);
		a = mul(a, a);
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	int n;
	cin >> n;
	int c[n];
	for (int i = 0; i < n; i++)
		cin >> c[i];
	sort(c, c+n, greater<int>());
	int pre[n+1] = {};
	for (int i = 0; i < n; i++)
		pre[i+1] = add(pre[i], c[i]);
	int invn = powmod(n, mod-2);
	for (int k = 1; k <= n; k++) {
		int ans = 0;
		for (int i = 0, j = 0; i < n; i += k, j++)
			ans = add(ans, mul(j, add(pre[min(n, i+k)], -pre[i])));
		cout << mul(ans, invn) << ' ';
	}
	cout << '\n';
	return 0;
}