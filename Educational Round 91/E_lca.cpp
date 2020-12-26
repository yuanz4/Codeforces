#include<bits/stdc++.h>
using namespace std;

const int N = 2e5+7;
const int L = 20;

int timer = 0;
int up[2*N][L];
vector<int> adj[2*N];
int tin[2*N], tout[2*N];
int idx[N];
int psum[N];
int cur[N];

void dfs(int v, int p) {
    tin[v] = ++timer;
    up[v][0] = p;
    for (int i = 1; i < L; ++i)
        up[v][i] = up[up[v][i-1]][i-1];
    for (int u : adj[v])
        dfs(u, v);
    tout[v] = ++timer;
}

bool is_ancestor(int u, int v) {
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int lca(int u, int v) {
    if (is_ancestor(u, v))
        return u;
    if (is_ancestor(v, u))
        return v;
    for (int i = L-1; i >= 0; --i) {
        if (!is_ancestor(up[u][i], v))
            u = up[u][i];
    }
    return up[u][0];
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < n; i++) {
		cin >> idx[i];
		idx[i]--;
	}
	for(int i = 0; i < m; i++)
		cur[i] = i;
	for(int i = 0; i < m - 1; i++){
		int x, y;
		cin >> x >> y;
		x--;
		y--;
		int new_idx = m + i;
		adj[new_idx].push_back(cur[x]);
		adj[new_idx].push_back(cur[y]);
		// the resulting tower has index x
		cur[x] = new_idx;
	}
	int root = m * 2 - 2;
    dfs(root, root);
	for(int i = 0; i < n-1; i++) {
		if (idx[i] == idx[i+1])
			// the neighbor elements belong to same disc
			psum[0]++;
		else {
			int p = lca(idx[i], idx[i+1]);
			// at lca they are combined
			psum[p-m+1]++;
		}
	}
	for(int i = 0; i < m - 1; i++)
		psum[i+1] += psum[i];
	for(int i = 0; i < m; i++)
		cout << n-1-psum[i] << '\n';
}