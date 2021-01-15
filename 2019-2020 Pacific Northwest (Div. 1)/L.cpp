#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll ans = -1;
string s;
int m, n;

void fail() {
	cout << -1 << '\n';
	exit(0);
}

void dfs(vector<int>& v, int pos) {
	if (ans != -1)
		return;
	if (pos == n) {
		for (int i = n - 2; i >= 0; i--) {
			int sum = 0;
			for (int j = 0; j <= i; j++)
				sum = (sum + v[n-1-j] * v[n-1-(i-j)]) % 10;
			if (sum != s[m-1-i] - '0')
				return;
		}
		ans = 0;
		for (auto& i: v) {
			ans *= 10;
			ans += i;
		}
		return;
	}
	int cur = s[pos] - '0';
	bool ok = false;
	for (int i = 0; i < 10; i++) {
		int sum = 0;
		v.push_back(i);
		for (int j = 0; j <= pos; j++)
			sum = (sum + v[j] * v[pos-j]) % 10;
		if (sum == cur) {
			ok = true;
			dfs(v, pos + 1);
		}
		v.pop_back();
	}
	if (!ok)
		return;
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	cin >> s;
	m = s.size();
	if (m % 2 == 0)
		fail();
	n = m / 2 + 1;
	vector<int> v;
	dfs(v, 0);
	if (ans == -1)
		fail();
	cout << ans << '\n';
	return 0;
}