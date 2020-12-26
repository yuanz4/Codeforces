#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	int test;
	cin >> test;
	while (test--) {
		int n;
		cin >> n;
		ll a[n];
		ll sum = 0;
		for (int i = 0; i < n; i++)
			cin >> a[i];
		if (n == 2) {
			cout << 0 << '\n';
			continue;
		}
		for (int i = 0; i < n-1; i++)
			sum += abs(a[i]-a[i+1]);
		ll ans = max(abs(a[0] - a[1]), abs(a[n-1] - a[n-2]));
		for (int i = 0; i < n-2; i++) {
			ans = max(ans,
				abs(a[i]-a[i+1]) + abs(a[i+1]-a[i+2]) - abs(a[i]-a[i+2]));
		}
		ans = sum - ans;
		cout << ans << '\n';
	}
	return 0;
}