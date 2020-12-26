#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	int test;
	cin >> test;
	while (test--) {
		int n, k, z;
		cin >> n >> k >> z;
		int a[n];
		for (int i = 0; i < n; i++)
			cin >> a[i];
		int ans = 0;
		int s = 0, mx = 0;
		for (int i = 0; i <= k; i++) {
			mx = max(mx, a[i]+a[i+1]);
			s += a[i];
			if (i % 2 == k % 2) {
				int t = (k - i) / 2;
				if (t <= z)
					ans = max(ans, s + mx * t);
			}
		}
		cout << ans << '\n';
	}
	return 0;
}