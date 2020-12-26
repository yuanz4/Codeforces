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
		vector<int> index;
		int p;
		int mx = 0;
		for (int i = 0; i < 2*n; i++) {
			cin >> p;
			if (p > mx) {
				index.push_back(i);
				mx = p;
			}
		}
		index.push_back(2*n);
		for (int i = 0; i < index.size()-1; i++)
			index[i] = index[i+1] - index[i];
		index.pop_back();
		int m = index.size();
		bool dp[n+1] = {};
		dp[0] = true;
		for (int i = 1; i <= m; i++) {
			for (int j = n; j >= index[i-1]; j--) {
				dp[j] = dp[j] | dp[j-index[i-1]];
			}
		}
		if (dp[n])
			cout << "YES" << '\n';
		else
			cout << "NO" << '\n';
	}
	return 0;
}