#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	int test;
	cin >> test;
	while (test--) {
		int n, k;
		cin >> n >> k;
		ll p[n];
		for (int i = 0; i < n; i++)
			cin >> p[i];
		ll pre[n];
		pre[0] = p[0];
		for (int i = 1; i < n; i++)
			pre[i] = pre[i-1] + p[i];
		ll ans = 0;
		for (int i = n-1; i >= 1; i--) {
			ll add = (100 * p[i] + k - 1) / k - pre[i-1];
			ans = max(ans, add);
		}
		cout << ans << '\n';
	}
	return 0;
}