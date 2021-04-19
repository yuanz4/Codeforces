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
		for (int i = 0; i < n; i++)
			cin >> a[i];
		ll INF = 1e18;
		ll ans = INF;
		ll mn[2] = {INF, INF};
		ll sum = 0;
		ll remain[2] = {n, n};
		for (int i = 0; i < n; i++) {
			int cur = i % 2;
			mn[cur] = min(mn[cur], a[i]);
			sum += a[i];
			remain[cur]--;
			if (i)
				ans = min(ans, sum+remain[0]*mn[0]+remain[1]*mn[1]);
		}
		cout << ans << '\n';
	}
	return 0;
}