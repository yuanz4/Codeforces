#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	int n;
	cin >> n;
	string s;
	cin >> s;
	s = '#' + s;
	ll total = 0, cur = 0;
	ll hist[n+1] = {};
	for (int i = 1; i <= n; i++) {
		if (s[i] == '0')
			total += cur;
		else {
			int l = i, r = i;
			while (r < n && s[r+1] == '1')
				r++;
			for (int x = 1; x <= (r-l+1); x++) {
				cur += l-1+x - hist[x];
				total += cur;
				hist[x] = r+1-x;
			}
			i = r;
		}
	}
	cout << total << '\n';
	return 0;
}