#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	int test;
	cin >> test;
	while (test--) {
		int n, p, k;
		cin >> n >> p >> k;
		string a;
		cin >> a;
		a = "#" + a;
		int x, y;
		cin >> x >> y;
		int d[n+1] = {};
		for (int i = n; i >= 1; i--) {
			if (a[i] == '0')
				d[i] = x;
			if (n-i >= k)
				d[i] += d[i+k];
		}
		int ans = x * n;
		for (int i = p; i <= n; i++) {
			int cur = (i - p) * y + d[i];
			ans = min(ans, cur);
		}
		cout << ans << '\n';
	}
	return 0;
}