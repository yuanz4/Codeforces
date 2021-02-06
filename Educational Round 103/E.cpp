#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void fail() {
	cout << "NO" << '\n';
	exit(0);
}

int n;
vector<vector<int>> adj;
vector<int> ans;

void topological_sort() {
    vector<int> in_degree(n, 0);
    for (int u = 0; u < n; u++) {
        for (int v: adj[u])
            in_degree[v]++;
    }
    queue<int> q;
    for (int i = 0; i < n; i++) {
        if (in_degree[i] == 0)
            q.push(i);
    }
    int cnt = 0;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        ans.push_back(u);
        for (int v: adj[u]) {
            if (--in_degree[v] == 0)
                q.push(v);
        }
        cnt++;
    }
    if (cnt != n)
    	fail();
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	int m, k;
	cin >> n >> m >> k;
	adj.resize(n);
	string p[n];
	unordered_map<string, int> index;
	for (int i = 0; i < n; i++) {
		cin >> p[i];
		index[p[i]] = i;
	}
	string s;
	int mt;
	while (m--) {
		cin >> s >> mt;
		mt--;
		bool ok = false;
		for (int j = 0; j < (1 << k); j++) {
			string cur = s;
			for (int l = 0; l < k; l++) {
				if ((j >> l) & 1)
					cur[l] = '_';
			}
			if (index.count(cur)) {
				if (index[cur] == mt)
					ok = true;
				else
					adj[mt].push_back(index[cur]);
			}
		}
		if (!ok)
			fail();
	}
	topological_sort();
	cout << "YES" << '\n';
	for (auto& i: ans)
		cout << i + 1 << ' ';
	cout << '\n';
	return 0;
}