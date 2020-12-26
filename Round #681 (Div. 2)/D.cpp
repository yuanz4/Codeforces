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
		int a[n];
		for (int i = 0; i < n; i++)
			cin >> a[i];
		int l = 0;
		while (l+1 < n && a[l] >= a[l+1]) {
			l++;
		}
		int pre = 0;
		int cut = a[l];
		bool ok = true;
		for (int i = l+1; i < n; i++) {
			if (a[i] < pre) {
				ok = false;
				break;
			}
			pre = max(pre, a[i]-cut);
			cut = a[i] - pre;
		}
		if (ok)
			cout << "YES" << '\n';
		else
			cout << "NO" << '\n';
	}
	return 0;
}