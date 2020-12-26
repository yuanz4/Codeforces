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
		int a[n];
		int mx = 0;
		ll sum = 0;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			mx = max(mx, a[i]);
			sum += a[i];
		}
		ll ans = mx * (n-1);
		if (ans >= sum)
			ans -= sum;
		else if (sum % (n-1) == 0)
			ans = 0;
		else
			ans = ((sum/(n-1))+1)*(n-1) - sum;
		cout << ans << '\n';
	}
	return 0;
}