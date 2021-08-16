#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll ans;

void dfs(int cur, ll count, bool first) {
	if (cur <= 1)
		ans = max(ans, count);
	for (int i = 2; i <= cur; i++) {
		if (first && i == 2)
			continue;
		if (cur % i)
			continue;
		dfs(cur / i - 1, count + 1, false);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	int test;
	cin >> test;
	for (int t = 1; t <= test; t++) {
		cout << "Case #" << t << ": ";
		int n;
		cin >> n;
		ans = 1;
		dfs(n, 0, true);
		cout << ans << '\n';
	}
	return 0;
}