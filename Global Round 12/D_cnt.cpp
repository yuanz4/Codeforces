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
		int a[n], cnt[n] = {};
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			a[i]--;
			cnt[a[i]]++;
		}
		string ans(n, '0');
		if (cnt[0])
			ans[n-1] = '1';
		int one = 0;
		for (int i = 0; i < n; i++) {
			if (cnt[i] == 1)
				one++;
		}
		ans[0] = (one == n) + '0';
		int i = 0;
		int l = 0, r = n-1;
		while (l < r) {
			if (--cnt[i] == 0 && (a[l] == i || a[r] == i) && cnt[i+1]) {
				if (a[l] == i)
					l++;
				else if (a[r] == i)
					r--;
				i++;
				ans[n-1-i] = '1';
			} else
				break;
		}
		cout << ans << '\n';
	}
	return 0;
}