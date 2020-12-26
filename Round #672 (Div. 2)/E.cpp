#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	int n;
	cin >> n;
	int a[n+1];
	for (int i = 0; i < n; i++)
		cin >> a[i];
	a[n] = 1;
	vector<int> zeros;
	int count = 0;
	for (int i = 0; i <= n; i++) {
		if (a[i] == 1) {
			zeros.push_back(count);
			count = 0;
		} else
			count++;
	}
	partial_sum(zeros.begin(), zeros.end(), zeros.begin());
	int interval = zeros.size();
	int cnt0 = zeros.back();
	int steps = n * (n-1) / 2;
	int dp[interval+1][cnt0+1][steps+1];
	for (int i = 0; i <= interval; i++)
		for (int j = 0; j <= cnt0; j++)
			for (int k = 0; k <= steps; k++)
				dp[i][j][k] = INT_MAX;

	dp[0][0][0] = 0;
	for (int i = 0; i < interval; i++) {
		for (int j = 0; j <= cnt0; j++) {
			for (int k = 0; k <= steps; k++) {
				if (dp[i][j][k] == INT_MAX)
					continue;
				for (int l = j; l <= cnt0; l++)
					dp[i+1][l][k+abs(zeros[i]-l)] = min(
						dp[i+1][l][k+abs(zeros[i]-l)], dp[i][j][k]+(l-j)*(l-j));
			}
		}
	}
	int mn = INT_MAX;
	for (int i = 0; i <= steps; i++) {
		mn = min(mn, dp[interval][cnt0][i]);
		int ans = (cnt0*cnt0-mn) / 2;
		cout << ans << ' ';
	}
	return 0;
}