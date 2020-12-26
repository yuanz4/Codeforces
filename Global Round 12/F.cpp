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
		int a[n], f[n] = {}, end[n] = {};
		int cut = 0;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			a[i]--;
			f[a[i]]++;
			if (i && a[i-1] == a[i]) {
				end[a[i-1]]++;
				end[a[i-1]]++;
				cut++;
			}
		}
		end[a[0]]++;
		end[a[n-1]]++;
		if (*max_element(f, f+n) > (n+1)/2) {
			cout << -1 << '\n';
			continue;
		}
		int mx = *max_element(end, end+n);
		cout << cut + max(0, mx-cut-2) << '\n';
	}
	return 0;
}