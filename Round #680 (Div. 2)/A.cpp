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
		int a[n], b[n];
		for (int i = 0; i < n; i++)
			cin >> a[i];
		for (int i = 0; i < n; i++)
			cin >> b[i];
		bool ok = true;
		for (int i = 0; i < n; i++) {
			if (a[i] + b[n-1-i] > x) {
				ok = false;
				break;
			}
		}
		if (ok)
			cout << "YES" << '\n';
		else
			cout << "NO" << '\n';
	}
	return 0;
}