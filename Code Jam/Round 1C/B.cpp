#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll inf = 2e18;
ll n, ans;

ll power(ll k) {
	ll ans = 1;
	while (k) {
		k /= 10;
		ans *= 10;
	}
	return ans;
}

ll match(int d, int x) {
	ll res = 0;
	for (int i = 0; i < d; i++) {
		int l = power(x);
		if (res > inf / l)
			return inf;
		res = res * l + x;
		x++;
	}
	return res;
}

void solve(int d) {
	int low = 0;
	int high = 1e9;
	while (low <= high) {
		int mid = (low + high) / 2;
		ll res = match(d, mid);
		if (res > n) {
			ans = min(ans, res);
			high = mid - 1;
		} else
			low = mid + 1;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	int test;
	cin >> test;
	for (int t = 1; t <= test; t++) {
		cout << "Case #" << t << ": ";
		cin >> n;
		ans = inf;
		for (int d = 2; d <= 18; d++)
			solve(d);
		cout << ans << '\n';
	}
	return 0;
}