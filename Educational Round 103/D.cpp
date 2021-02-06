#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<vector<vector<int>>> d;
int n;
string s;

// dir: 0 for left, 1 for right
int dfs(int u, int flip, int dir) {
	if (d[u][flip][dir] != -1)
		return d[u][flip][dir];
	if (dir == 0 && u != 0) {
		if ((!flip && s[u-1] == 'L') || (flip && s[u-1] == 'R'))
			return d[u][flip][dir] = dfs(u-1, 1-flip, dir) + 1;
	} else if (dir == 1 && u != n) {
		if ((!flip && s[u] == 'R') || (flip && s[u] == 'L'))
			return d[u][flip][dir] = dfs(u+1, 1-flip, dir) + 1;
	}
	return d[u][flip][dir] = 0;
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	int test;
	cin >> test;
	while (test--) {
		cin >> n;
		cin >> s;
		d.assign(n+1, vector<vector<int>>(2, vector<int>(2, -1)));
		for (int i = 0; i <= n; i++) {
			int ans = 1;
			if (i != 0)
				ans += dfs(i, 0, 0);
			if (i != n)
				ans += dfs(i, 0, 1);
			cout << ans << ' ';
		}
		cout << '\n';
	}
	return 0;
}