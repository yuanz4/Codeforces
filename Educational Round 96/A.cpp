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
		bool ok = false;
		for (int i = 0; i <= n/3; i++) {
			int left = n - i * 3;
			for (int j = 0; j <= left/5; j++) {
				int l = left - j * 5;
				if (l % 7 == 0) {
					ok = true;
					cout << i << " " << j << " " << l/7 << '\n';
					break;
				}
			}
			if (ok)
				break;
		}
		if (!ok)
			cout << -1 << '\n';
	}
	return 0;
}