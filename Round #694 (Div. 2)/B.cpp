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
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			sum += a[i];
		}
		ll b[n] = {};
		for (int i = 0; i < n; i++) {
			int cur = a[i];
			while (true) {
				if (cur % x == 0) {
					cur /= x;
					b[i]++;
				} else
					break;
			}
		}
		ll suf = n-1;
		for (int i = n-1; i >= 0; i--) {
			if (b[i] <= b[suf])
				suf = i;
		}
		for (int i = 0; i < n; i++) {
			if (i < suf)
				sum += (b[suf] + 1) * a[i];
			else
				sum += b[suf] * a[i];
		}
		cout << sum << '\n';
	}
	return 0;
}