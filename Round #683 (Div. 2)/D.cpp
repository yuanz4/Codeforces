#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	int n, m;
	cin >> n >> m;
	string a, b;
	cin >> a >> b;
	int d[n+1][m+1] = {};
	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int add = -2;
			if (a[i] == b[j])
				add = 2;
			d[i+1][j+1] = max(0, max(d[i][j]+add,
				max(d[i][j+1]-1, d[i+1][j]-1)));
			ans = max(ans, d[i+1][j+1]);
		}
	}
	cout << ans << '\n';
	return 0;
}