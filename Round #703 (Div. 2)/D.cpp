#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	int n, k;
	cin >> n >> k;
	int a[n];
	for (int i = 0; i < n; i++)
		cin >> a[i];
	int low = 1, high = n;
	int ans = 0;
	while (low <= high) {
		int mid = (low + high) / 2;
		int b[n];
		for (int i = 0; i < n; i++)
			b[i] = a[i] >= mid ? 1 : -1;
		for (int i = 1; i < n; i++)
			b[i] += b[i-1];
		int mn = 0;
		int mx = b[k-1];
		for (int i = k; i < n; i++) {
			mn = min(mn, b[i-k]);
			mx = max(mx, b[i] - mn);
		}
		if (mx > 0) {
			ans = mid;
			low = mid + 1;
		} else
			high = mid - 1;
	}
	cout << ans << '\n';
	return 0;
}