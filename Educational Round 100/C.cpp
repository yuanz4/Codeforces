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
		int t[n+1], x[n+1];
		for (int i = 0; i < n; i++)
			cin >> t[i] >> x[i];
		t[n] = INT_MAX;
		int start = 0, end = 0;
		int time = 0, dir = 1, last = 0;
		int ans = 0;
		for (int i = 0; i <= n; i++) {
			int total = abs(end - start);
			if (i)
				time += t[i] - t[i-1];
			if (total > time) {
				// ignore command
				int cur = dir * time + start;
				if ((x[i-1] >= last && x[i-1] <= cur) ||
					(x[i-1] <= last && x[i-1] >= cur)) {
					ans++;
				}
				last = cur;
			} else {
				// new command
				if (i) {
					if ((x[i-1] >= last && x[i-1] <= end) ||
						(x[i-1] <= last && x[i-1] >= end)) {
						ans++;
					}
				}
				start = end;
				end = x[i];
				time = 0;
				last = start;
				dir = (end - start) > 0 ? 1 : -1;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}