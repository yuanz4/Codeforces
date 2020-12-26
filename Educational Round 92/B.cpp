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
		for (int t = 0; t <= z; t++) {
			int pos = k - 2 * t;
			if (pos < 0)
				continue;
			int mx = 0, s = 0;
			for (int i = 0; i <= pos; i++) {
				mx = max(mx, a[i] + a[i+1]);
				s += a[i];
			}
			ans = max(ans, s + mx * t);
		}
		cout << ans << '\n';
	}
	return 0;
}