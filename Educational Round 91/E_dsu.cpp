#include <bits/stdc++.h>
using namespace std;

vector<int> p;

int find(int x){
	if (x == p[x])
		return x;
	return p[x] = find(p[x]);
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	
	int n, m;
	cin >> n >> m;
	p.resize(m);
	vector<int> val[m];
	int disc[n];
	int ans = n - 1;
	for (int i = 0; i < m; i++)
		p[i] = i;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		x--;
		disc[i] = x;
		ans -= (i && disc[i] == disc[i - 1]);
		val[disc[i]].push_back(i);
	}
	cout << ans << '\n';
	for (int i = 0; i < m-1; i++) {
		int u, v;
		cin >> u >> v;
		u = find(u-1), v = find(v-1);
		if (val[u].size() < val[v].size())
			swap(u, v);
		for (int x : val[v]){
			if (x)
				ans -= disc[x-1] == u;
			if (x < n-1)
				ans -= disc[x+1] == u;
		}
		for (int x : val[v]){
			val[u].push_back(x);
			disc[x] = u;
		}
		p[v] = u;
		cout << ans << '\n';
	}
	return 0;
}