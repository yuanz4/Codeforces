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
		int x[n], y[n];
		for (int i = 0; i < n; i++)
			cin >> x[i] >> y[i];
		bool ok = false;
		for (int i = 0; i < n; i++) {
			bool cur = true;
			for (int j = 0; j < n; j++) {
				if (abs(x[i]-x[j]) + abs(y[i]-y[j]) > k) {
					cur = false;
					break;
				}
			}
			if (cur) {
				ok = cur;
				break;
			}
		}
		if (ok)
			cout << 1 << '\n';
		else
			cout << -1 << '\n';
	}
	return 0;
}