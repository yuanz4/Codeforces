#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	int test;
	cin >> test;
	while (test--) {
		int n, m;
		cin >> n >> m;
		int nxt[n+1] = {}, x[m], y[m];
		bool visited[n+1] = {};
		for (int i = 0; i < m; i++) {
			cin >> x[i] >> y[i];
			nxt[x[i]] = y[i];
		}
		int ans = m;
		for (int i = 0; i < m; i++) {
			if (visited[x[i]])
				continue;
			if (x[i] == y[i]) {
				ans--;
				continue;
			}
			int u = x[i];
			while (u && !visited[u]) {
				visited[u] = true;
				u = nxt[u];
			}
			if (u == x[i])
				ans++;
		}
		cout << ans << '\n';
	}
	return 0;
}