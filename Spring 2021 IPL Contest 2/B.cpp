#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAXN = 1e5 + 7;

int last[MAXN];
int dist[MAXN];

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	int n;
	cin >> n;
	vector<unordered_set<int>> adj(n + 1);
	for (int i = 1; i <= n; i++) {
		int k;
		cin >> k;
		for (int j = 0; j < k; j++) {
			int p;
			cin >> p;
			if (last[p] != 0)
				adj[last[p]].insert(i);
			last[p] = i;
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		ans = max(ans, dist[i]);
		for (auto& j: adj[i])
			dist[j] = max(dist[j], dist[i] + 1);
	}
	cout << ans + 1 << '\n';
	return 0;
}