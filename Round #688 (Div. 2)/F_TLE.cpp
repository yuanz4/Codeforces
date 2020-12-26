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
		int a[n], d[n][n] = {};
		for (int i = 0; i < n; i++)
			cin >> a[i];
		for (int i = 1; i < n; i++) {
			int cnt = 0;
			for (int j = i; j < n; j++)
				d[i][j] = n;
			for (int j = i - 1; j >= 0; j--) {
				int jump = j + a[j];
				if (jump >= i && jump < n) {
					int pre = n;
					for (int k = j; k < i; k++)
						pre = min(pre, d[j][k]);
					d[i][jump] = min(d[i][jump], pre + cnt++);
				}
			}
		}
		cout << d[n-1][n-1] << '\n';
	}
	return 0;
}