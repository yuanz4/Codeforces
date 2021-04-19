#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n;

void add(ll count[], int l, int r, int inc) {
	if (l > r || inc < 0)
		return;
	if (l <= n)
		count[l] += inc;
	if (r + 1 <= n)
		count[r+1] -= inc;
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	int test;
	cin >> test;
	while (test--) {
		cin >> n;
		int a[n+1];
		for (int i = 1; i <= n; i++)
			cin >> a[i];
		ll ans = 0;
		ll count[n+1] = {};
		for (int i = 1; i <= n; i++) {
			count[i] += count[i-1];
			add(count, i+2, i+a[i], 1);
			if (count[i] < a[i] - 1)
				ans += a[i] - 1 - count[i];
			else
				add(count, i+1, i+1, count[i]-a[i]+1);
		}
		cout << ans << '\n';
	}
	return 0;
}