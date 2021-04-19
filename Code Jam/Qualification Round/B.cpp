#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	int test;
	cin >> test;
	for (int t = 1; t <= test; t++) {
		cout << "Case #" << t << ": ";
		int x, y;
		cin >> x >> y;
		string s;
		cin >> s;
		int n = s.size();
		int d[n][2];
		memset(d, 0x3f, sizeof(d));
		d[0][0] = d[0][1] = 0;
		// 0 for C, 1 for J
		// CJ for x, JC for y
		for (int i = 1; i < n; i++) {
			if (s[i] == 'C') {
				if (s[i-1] == 'J')
					d[i][0] = d[i-1][1] + y;
				else if (s[i-1] == '?')
					d[i][0] = min(d[i-1][1] + y, d[i-1][0]);
				else
					d[i][0] = d[i-1][0];
				d[i][1] = INF;
			} else if (s[i] == 'J') {
				if (s[i-1] == 'C')
					d[i][1] = d[i-1][0] + x;
				else if (s[i-1] == '?')
					d[i][1] = min(d[i-1][0] + x, d[i-1][1]);
				else
					d[i][1] = d[i-1][1];
				d[i][0] = INF;
			} else {
				if (s[i-1] == 'C') {
					d[i][0] = d[i-1][0];
					d[i][1] = d[i-1][0] + x;
				} else if (s[i-1] == 'J') {
					d[i][0] = d[i-1][1] + y;
					d[i][1] = d[i-1][1];
				} else {
					d[i][0] = min(d[i-1][0], d[i-1][1] + y);
					d[i][1] = min(d[i-1][0] + x, d[i-1][1]);
				}
			}
		}
		cout << min(d[n-1][0], d[n-1][1]) << '\n';
	}
	return 0;
}