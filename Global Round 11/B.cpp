#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		string s;
		cin >> s;
		int start = 0;
		for (int i = 0; i < n; i++) {
			if (s[i] == 'L')
				start++;
			else
				break;
		}
		int end = 0;
		for (int i = n-1; i >= 0; i--) {
			if (s[i] == 'L')
				end++;
			else
				break;
		}
		int ans = 0;
		if (start == n) {
			if (k)
				ans += 2*min(k, n)-1;
			cout << ans << '\n';
		} else {
			multiset<int> lost;
			for (int i = start; i < n-end;) {
				if (s[i] == 'W') {
					while (s[i] == 'W') {
						ans += 2;
						i++;
					}
					ans--;
				} else {
					int l = 0;
					while (s[i] == 'L') {
						l++;
						i++;
					}
					lost.insert(l);
				}
			}
			for (int i: lost) {
				if (k) {
					if (k >= i) {
						ans += 2*i+1;
						k -= i;
					} else {
						ans += 2*k;
						k = 0;
					}
				} else
					break;
			}
			ans += 2*min(k, start+end);
			cout << ans << '\n';
		}
	}
	return 0;
}