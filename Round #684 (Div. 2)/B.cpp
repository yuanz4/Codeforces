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
		int a[n*k];
		for (int i = 0; i < n*k; i++)
			cin >> a[i];
		int mid = (n+1) / 2;
		ll ans = 0;
		for (int i = k*(mid-1); i < n*k; i += n-mid+1)
			ans += a[i];
		cout << ans << '\n';
	}
	return 0;
}