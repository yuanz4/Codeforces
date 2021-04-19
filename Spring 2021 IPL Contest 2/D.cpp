#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;

vector<vi> adj;

vi dfs(int u) {
	vi last;
	for (auto& v: adj[u]) {
		vi pre[2];
		pre[0] = pre[1] = last;
		reverse(pre[1].begin(), pre[1].end());
		vi cur = dfs(v);
		for (int i = 0; i < cur.size(); i++) {
			last.push_back(cur[i]);
			int order = 1 - i % 2;
			last.insert(last.end(), pre[order].begin(), pre[order].end());
		}
	}
	if (u != 1)
		last.insert(last.begin(), u);
	return last;
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	int n;
	cin >> n;
	adj.resize(n + 1);
	for (int i = 2; i <= n; i++) {
		int p;
		cin >> p;
		adj[p].push_back(i);
	}
	vi ans = dfs(1);
	cout << ans.size() << '\n';
	for (auto& i: ans)
		cout << i << ' ';
	cout << '\n';
	return 0;
}