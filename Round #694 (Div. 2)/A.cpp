#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	int test;
	cin >> test;
	while (test--) {
		int n, x;
		cin >> n >> x;
		int a[n];
		ll sum = 0;
		ll mx = 0;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			mx += a[i] / x + (a[i] % x != 0);
			sum += a[i];
		}
		ll mi = sum / x + (sum % x != 0);
		cout << mi << " " << mx << '\n';
	}
	return 0;
}