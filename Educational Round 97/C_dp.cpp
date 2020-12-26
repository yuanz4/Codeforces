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
		int t[n];
		for (int i = 0; i < n; i++)
			cin >> t[i];
		sort(t, t+n);
		int dp[n+1][2*n+1];
		memset(dp, 0x3f, sizeof(dp));
		for (int i = 0; i <= 2*n; i++)
			dp[0][i] = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= 2*n; j++) {
				dp[i][j] = dp[i][j-1];
				dp[i][j] = min(dp[i][j], dp[i-1][j-1]+abs(t[i-1]-j));
			}
		}
		cout << dp[n][2*n] << '\n';
	}
	return 0;
}