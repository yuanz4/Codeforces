#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n;
		string A, B;
		cin >> n >> A >> B;
		int alp = 20;
		vector<vector<int>> adj(alp, vector<int>());
		bool good = true;
		for (int i = 0; i < n; i++) {
			char a = A[i], b = B[i];
			if (a != b) {
				if (a > b) {
					cout << -1 << '\n';
					good = false;
					break;
				}
				adj[A[i]-'a'].push_back(B[i]-'a');
				adj[B[i]-'a'].push_back(A[i]-'a');
			}
		}
		if (!good)
			continue;
		vector<bool> visited(alp);
		function<void(int)> dfs = [&](int u) {
			visited[u] = true;
		    for (int v: adj[u]) {
		        if (!visited[v])
		            dfs(v);
			}
		};
		int ans = alp;
		for (int i = 0; i < alp; i++) {
			if (!visited[i]) {
				dfs(i);
				ans--;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}