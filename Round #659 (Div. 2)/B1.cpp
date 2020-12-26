#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	int test;
	cin >> test;
	while (test--) {
		int n, k, l;
		cin >> n >> k >> l;
		int d[n+1];
		for (int i = 1; i <= n; i++)
			cin >> d[i];
		int total = 2*n*k+7;
		vector<bool> prev(n+2, false), cur(n+2, false);
		for (int t = 0; t < total; t++) {
			cur.assign(n+2, 0);
			prev[0] = true;
			for (int i = 1; i <= n+1; i++) {
				int p = t % (2*k);
				if (p > k)
					p = 2*k - p;
				int depth;
				if (i <= n)
					depth = d[i] + p;
				else
					depth = 0;
				if (depth <= l) {
					if (prev[i-1])
						cur[i] = true;
					if (prev[i])
						cur[i] = true;
				}
			}
			swap(prev, cur);
		}
		if (prev[n+1] == true)
			cout << "YES" << '\n';
		else
			cout << "NO" << '\n';
	}
	return 0;
}