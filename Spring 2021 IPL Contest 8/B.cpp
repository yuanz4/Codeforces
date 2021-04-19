#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll mod = 1e9+7;

void mul(ll& a, ll b) {
	a = (a * b) % mod;
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	int test;
	cin >> test;
	while (test--) {
		int n;
		cin >> n;
		int a[n];
		for (int i = 0; i < n; i++)
			cin >> a[i];
		int common = a[0];
		unordered_map<int, int> m;
		for (int i = 0; i < n; i++) {
			common &= a[i];
			m[a[i]]++;
		}
		int freq = m[common];
		if (freq < 2)
			cout << 0 << '\n';
		else {
			ll ans = 1;
			mul(ans, freq);
			mul(ans, freq-1);
			for (int i = 1; i <= n - 2; i++)
				mul(ans, i);
			cout << ans << '\n';
		}
	}
	return 0;
}