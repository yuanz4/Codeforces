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
		int ans = INT_MAX;
		for (int i = 0; i < 2; i++) {
			string now;
			int c = i;
			for (int j = 0; j < n; j++) {
				now += c + '0';
				c = 1 - c;
			}
			int cur = 0;
			for (int j = 0; j < n; j++) {
				if (s[j] != now[j]) {
					int r = j;
					while (r+1 < n && s[r] != s[r+1]) {
						r++;
					}
					cur++;
					j = r;
				}
			}
			ans = min(ans, cur);
		}
		cout << ans << '\n';
	}
	return 0;
}