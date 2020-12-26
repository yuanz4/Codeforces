#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	int test;
	cin >> test;
	while (test--) {
		int n;
		cin >> n;
		string s;
		cin >> s;
		char c = '<';
		bool ok = true;
		for (auto& i: s) {
			if (i == '-')
				continue;
			if (i != c) {
				ok = false;
				break;
			}
		}
		if (ok) {
			cout << n << '\n';
			continue;
		}
		c = '>';
		ok = true;
		for (auto& i: s) {
			if (i == '-')
				continue;
			if (i != c) {
				ok = false;
				break;
			}
		}
		if (ok) {
			cout << n << '\n';
			continue;
		}
		s += s[0];
		int ans = 0;
		for (int i = 0; i < n; i++) {
			if (s[i] == '-' || s[i+1] == '-')
				ans++;
		}
		cout << ans << '\n';
	}
	return 0;
}