#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	int test;
	cin >> test;
	while (test--) {
		int n, c0, c1, h;
		cin >> n >> c0 >> c1 >> h;
		string s;
		cin >> s;
		int zero = 0, one = 0;
		int ans = 0;
		for (auto& i: s) {
			if (i == '0') {
				zero++;
				ans += c0;
			} else {
				one++;
				ans += c1;
			}
		}
		if (c1 + h - c0 < 0)
			ans += zero * (c1 + h - c0);
		else if (c0 + h - c1 < 0)
			ans += one * (c0 + h - c1);
		cout << ans << '\n';
	}
	return 0;
}