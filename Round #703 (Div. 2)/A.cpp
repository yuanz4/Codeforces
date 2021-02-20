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
		ll a[n];
		for (int i = 0; i < n; i++)
			cin >> a[i];
		bool ok = true;
		for (int i = 0; i < n; i++) {
			if (a[i] < i) {
				ok = false;
				break;
			}
			if (i != n - 1)
				a[i+1] += a[i] - i;
		}
		if (ok)
			cout << "YES" << '\n';
		else
			cout << "NO" << '\n';
	}
	return 0;
}