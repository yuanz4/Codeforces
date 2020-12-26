#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    string s;
    cin >> s;
	int same[n+2][2] = {};
	int prv[n+1][2] = {};
	prv[0][0] = prv[0][1] = INT_MAX;
	for (int i = n; i > 0; i--) {
		if (s[i-1] != '1')
			same[i][0] += same[i+1][0] + 1;
		if (s[i-1] != '0')
			same[i][1] += same[i+1][1] + 1;
	}
	for (int i = 1; i <= n; i++) {
		if (s[i-1] == '1')
			prv[i][0] = INT_MAX;
		else if (prv[i-1][0] == INT_MAX)
			prv[i][0] = i;
		else
			prv[i][0] = prv[i-1][0];
		if (s[i-1] == '0')
			prv[i][1] = INT_MAX;
		else if (prv[i-1][1] == INT_MAX)
			prv[i][1] = i;
		else
			prv[i][1] = prv[i-1][1];
	}
	for (int x = 1; x <= n; x++) {
		int pos = 1, ans = 0;
		while (pos <= n) {
			if (same[pos][0] >= x || same[pos][1] >= x) {
				pos += x;
				ans++;
			} else {
				if (pos+x <= n)
					pos = min(prv[pos+x][0], prv[pos+x][1]);
				else
					break;
			}
		}
		cout << ans << ' ';
	}
	cout << '\n';
	return 0;
}