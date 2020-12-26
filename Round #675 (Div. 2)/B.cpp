#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	int test;
	cin >> test;
	while (test--) {
		int n, m;
		cin >> n >> m;
		ll a[n][m];
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				cin >> a[i][j];
		ll ret = 0;
		for (int i = 0; i < (n+1)/2; i++) {
			for (int j = 0; j < (m+1)/2; j++) {
				vector<ll> avg;
				avg.push_back(a[i][j]);
				if (n-i-1 != i)
					avg.push_back(a[n-i-1][j]);
				if (m-j-1 != j)
					avg.push_back(a[i][m-j-1]);
				if (n-i-1 != i && m-j-1 != j)
					avg.push_back(a[n-i-1][m-j-1]);
				sort(avg.begin(), avg.end());
				ll median = avg[avg.size()/2];
				for (ll e: avg)
					ret += abs(e-median);
			}
		}
		cout << ret << '\n';
	}
	return 0;
}