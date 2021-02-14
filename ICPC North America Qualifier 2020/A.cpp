#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<unordered_set<int>> g, gr;
vector<bool> used;
vector<int> order, component;

void dfs1(int v) {
    used[v] = true;
    for (auto& i: g[v])
        if (!used[i])
            dfs1(i);
    order.push_back(v);
}

void dfs2(int v) {
    used[v] = true;
    component.push_back(v);
    for (auto& i: gr[v]) {
        if (!used[i])
            dfs2(i);
    }
}

// name: speak, understand
unordered_map<int, pair<string, unordered_set<string>>> m;
unordered_set<int> visited;

void dfs(int u) {
	if (visited.count(u))
		return;
	visited.insert(u);
	auto info = m[u];
	string speak = info.first;
	for (auto& i: m) {
		int v = i.first;
		if (v == u)
			continue;
		auto understand = m[v].second;
		if (understand.count(speak)) {
			g[u].insert(v);
			gr[v].insert(u);
			dfs(v);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	string line;
	getline(cin, line);
	int n = stoi(line);
	vector<string> name(n);
	for (int i = 0; i < n; i++) {
		getline(cin, line);
		istringstream in(line);
		vector<string> v;
		string t;
		while (in >> t)
			v.push_back(t);
		name[i] = v[0];
		unordered_set<string> cur;
		for (int j = 1; j < v.size(); j++)
			cur.insert(v[j]);
		m[i] = {v[1], cur};
	}
	g.resize(n);
	gr.resize(n);
	for (int i = 0; i < n; i++)
		dfs(i);

	int ans = 0;
	used.assign(n, false);
    for (int i = 0; i < n; i++)
        if (!used[i])
            dfs1(i);
    used.assign(n, false);
    for (int i = 0; i < n; i++) {
        int v = order[n-1-i];
        if (!used[v]) {
            dfs2(v);
            ans = max(ans, (int)component.size());
            component.clear();
        }
    }
	cout << n - ans << '\n';
	return 0;
}