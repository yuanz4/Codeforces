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
	int m = 0;
	for (int i = 1; i <= n; i++) {
		if (i == 1 || a[i] != a[i-1])
			a[++m] = a[i];
	}
	int last[n+1];
	for (int i = 1; i <= n; i++)
		last[i] = -1;
	int ans = m;
	int f[m+1];
	f[0] = 0;
	f[1] = 1;
	last[a[1]] = 1;
	for (int i = 2; i <= m; i++) {
		auto g = [&](int j) {
			if (j == 0)
				return INT_MAX;
			return f[j] + (i - j - 1) + (a[j - 1] != a[i]);
		};
		int j = last[a[i]] + 1;
		f[i] = min(g(i-1), g(j));
		ans = min(ans, f[i] + m - i);
		last[a[i]] = i;
	}
	cout << ans << '\n';
	return 0;
}