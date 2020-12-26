#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int mx = 100007;
int zero[2][mx], one[2][mx];

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	string s;
	cin >> s;
	int n = s.size();
	s = '#' + s;
	ll x, y;
	cin >> x >> y;
	vector<int> mark;
	for (int i = 1; i <= n; i++) {
		zero[0][i] = zero[0][i-1] + (s[i] == '0');
		one[0][i] = one[0][i-1] + (s[i] == '1');
		if (s[i] == '?')
			mark.push_back(i);
	}
	for (int i = n; i >= 1; i--) {
		zero[1][i] = zero[1][i+1] + (s[i] == '0');
		one[1][i] = one[1][i+1] + (s[i] == '1');
	}
	ll sum = 0;
	for (int i = 1; i <= n; i++) {
		if (s[i] == '0')
			sum += one[1][i+1] * x;
		else if (s[i] == '1')
			sum += zero[1][i+1] * y;
	}
	ll ans;
	int m = mark.size();
	if (x <= y) {
		// all mark as one
		for (int i: mark)
			sum += zero[0][i-1] * x + zero[1][i+1] * y;
		ans = sum;
		// set to zero from left to right
		for (int i = 0; i < m; i++) {
			sum -= (zero[0][mark[i]-1] + i) * x + zero[1][mark[i]+1] * y;
			sum += one[0][mark[i]-1] * y + (one[1][mark[i]+1] + m-1-i) * x;
			ans = min(ans, sum);
		}
	} else {
		// all mark as zero
		for (int i: mark)
			sum += one[0][i-1] * y + one[1][i+1] * x;
		ans = sum;
		// set to one from left to right
		for (int i = 0; i < m; i++) {
			sum -= (one[0][mark[i]-1] + i) * y + one[1][mark[i]+1] * x;
			sum += zero[0][mark[i]-1] * x + (zero[1][mark[i]+1] + m-1-i) * y;
			ans = min(ans, sum);
		}
	}
	cout << ans << '\n';
	return 0;
}