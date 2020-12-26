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
		int p[n];
		for (int i = 0; i < n; i++)
			cin >> p[i];
		int l, r;
		int pre = n+1, after = n+1;
		for (l = 0; l < n; l++) {
			if (p[l] < pre)
				pre = p[l];
			else
				break;
		}
		l--;
		for (r = n-1; r >= 0; r--) {
			if (p[r] < after)
				after = p[r];
			else
				break;
		}
		r++;
		if (l == r)
			cout << "NO" << '\n';
		else {
			cout << "YES" << '\n';
			int i;
			for (i = l+1; i < r; i++) {
				if (p[i] > p[l] && p[i] > p[r])
					break;
			}
			cout << l+1 << " " << i+1 << " " << r+1 << '\n';
		}
	}
	return 0;
}