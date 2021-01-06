#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	int test;
	cin >> test;
	while (test--) {
		int n, m;
		cin >> n >> m;
		int k[n], c[m];
		for (int i = 0; i < n; i++) {
			cin >> k[i];
			k[i]--;
		}
		sort(k, k+n);
		for (int i = 0; i < m; i++)
			cin >> c[i];
		ll ans = 0;
		int nxt = 0;
		for (int i = n-1; i >= 0; i--) {
			if (c[k[i]] > c[nxt])
				ans += c[nxt++];
			else
				ans += c[k[i]];
		}
		cout << ans << '\n';
	}
	return 0;
}