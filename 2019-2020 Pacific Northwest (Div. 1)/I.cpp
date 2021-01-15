#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX = 505;
const int inf = INT_MAX, N = MAX + 2, M = (MAX + 2) * (MAX + 2);
int head[N], ver[M], edge[M], Next[M];
int v[N], incf[N], pre[N];
int s, t, tot, maxflow;

void add(int x, int y, int z) {
	ver[++tot] = y, edge[tot] = z, Next[tot] = head[x], head[x] = tot;
	ver[++tot] = x, edge[tot] = 0, Next[tot] = head[y], head[y] = tot;
}

bool bfs() {
	memset(v, 0, sizeof(v));
	queue<int> q;
	q.push(s);
	v[s] = 1;
	incf[s] = inf;
	while (q.size()) {
		int x = q.front();
		q.pop();
		for (int i = head[x]; i; i = Next[i]) {
			if (edge[i]) {
				int y = ver[i];
				if (v[y])
					continue;
				incf[y] = min(incf[x], edge[i]);
				pre[y] = i;
				q.push(y);
				v[y] = 1;
				if (y == t)
					return true;
			}
		}
	}
	return false;
}

void update() {
	int x = t;
	while (x != s) {
		int i = pre[x];
		edge[i] -= incf[t];
		edge[i^1] += incf[t];
		x = ver[i^1];
	}
	maxflow += incf[t];
}

int parity(string w) {
	int l = w.size();
	bool p = false;
	for (int i = 0; i < l; i++) {
		for (int j = i + 1; j < l; j++) {
			if (w[i] > w[j])
				p = !p;
		}
	}
	return p;
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	int n;
	cin >> n;
	s = n;
	t = n + 1;
	tot = 1;
    maxflow = 0;
    string a[n];
    unordered_map<string, int> words;
    for (int i = 0; i < n; i++) {
    	cin >> a[i];
    	words[a[i]] = i;
    }
    int l = a[0].size();
    vector<vector<int>> par(2);
    for (int i = 0; i < n; i++) {
    	int p = parity(a[i]);
    	par[p].push_back(i);
    	if (!p) {
    		for (int j = 0; j < l; j++) {
    			for (int k = j + 1; k < l; k++) {
    				string adj(a[i]);
    				swap(adj[j], adj[k]);
    				if (words.count(adj))
    					add(i, words[adj], 1);
    			}
    		}
    	}
    }
    for (auto& i: par[0])
    	add(n, i, 1);
    for (auto& i: par[1])
    	add(i, n+1, 1);
    while (bfs())
    	update();
	cout << n - maxflow << '\n';
	return 0;
}