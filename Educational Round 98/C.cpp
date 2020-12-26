#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	int test;
	cin >> test;
	while (test--) {
		string s;
		cin >> s;
		int ans = 0;
		int la = 0, lb = 0;
		int n = s.size();
		for (int i = 0; i < n; i++) {
			if (s[i] == '(')
				la++;
			else if (s[i] == '[')
				lb++;
			else if (s[i] == ')') {
				if (la) {
					la--;
					ans++;
				}
			} else {
				if (lb) {
					lb--;
					ans++;
				}
			}
		}
		cout << ans << '\n';
	}
	return 0;
}