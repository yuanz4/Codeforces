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
		ll c[n], a[n], b[n];
		for (int i = 0; i < n; i++)
			cin >> c[i];
		for (int i = 0; i < n; i++)
			cin >> a[i];
		for (int i = 0; i < n; i++)
			cin >> b[i];
		ll ans = 0;
		ll cur = abs(a[1] - b[1]);
		for (int i = 1; i < n; i++) {
			cur += 2;
			ans = max(ans, cur + c[i] - 1);
			if (i == n-1)
				break;
			if (a[i+1] == b[i+1])
				cur = 0;
			else {
				ll len = abs(a[i+1] - b[i+1]);
				cur += c[i] - 1 - len;
				cur = max(cur, len);
			}
		}
		cout << ans << '\n';
	}
	return 0;
}