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
		int prev = -1;
		int count = 0;
		int i = 0;
		while (i < n) {
			int r = i;
			while (r + 1 < n && a[r+1] == a[i]) {
				r++;
			}
			if (a[i] == prev) {
				count++;
				prev = a[i] + 1;
			} else if (r - i + 1 > 1) {
				count += 2;
				prev = a[i] + 1;
			} else {
				count++;
				prev = a[i];
			}
			i = r + 1;
		}
		cout << count << '\n';
	}
	return 0;
}