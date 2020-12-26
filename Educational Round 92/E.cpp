#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll gcd(ll a, ll b) {
	if (b == 0)
		return a;
	return gcd(b, a%b);
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	int test;
	cin >> test;
	while (test--) {
		ll m, d, w;
		cin >> m >> d >> w;
		ll w2 = w / gcd(w, d-1);
		ll mx = min(m, d);
		ll cnt = mx / w2;
		ll ans = mx * cnt - w2 * (cnt+1) * cnt / 2;
		cout << ans << '\n';
	}
	return 0;
}