#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	int n;
	cin >> n;
	int a[n+1];
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	map<int, int> level;
	bool three = false;
	for (int i = 1; i <= n; i++) {
		int zero = __builtin_clz(a[i]);
		level[zero]++;
		if (level[zero] == 3) {
			three = true;
			break;
		}
	}
	if (three) {
		cout << 1 << '\n';
		return 0;
	}
	int s[n+1] = {};
	for (int i = 1; i <= n; i++)
		s[i] = a[i] ^ s[i-1];
	int ans = n;
	for (int l = 1; l < n; l++) {
		for (int r = l+1; r <= n; r++) {
			for (int k = l; k < r; k++) {
				int first = s[k] ^ s[l-1];
				int second = s[r] ^ s[k];
				if (first > second)
					ans = min(ans, r-l-1);
			}
		}
	}
	if (ans == n)
		cout << -1 << '\n';
	else
		cout << ans << '\n';
	return 0;
}