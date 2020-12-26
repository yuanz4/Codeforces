#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

struct point {
	int x, y;
	int id;
};

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll n, m;
    cin >> n >> m;
    m += 2;
    point p[m];
	cin >> p[0].x >> p[0].y;
	cin >> p[m-1].x >> p[m-1].y;
	for (int i = 1; i < m-1; i++)
		cin >> p[i].x >> p[i].y;
	for (int i = 0; i < m; i++)
		p[i].id = i;
	vector<pii> adj[m];
	
	// add back edge to target first, because id == i
	// sort except target, we don't want forward edge from target
	// we also don't want back edge to start
	for (int i = 0; i < m-1; i++)
		adj[i].push_back({m-1, abs(p[i].x-p[m-1].x) + abs(p[i].y-p[m-1].y)});
	sort(p, p+m-1, [](point& a, point& b) {
		return a.x < b.x;
	});
	for (int i = 1; i < m-1; i++) {
		int dist = p[i].x - p[i-1].x;
		if (p[i].id != 0)
			adj[p[i-1].id].push_back({p[i].id, dist});
		if (p[i-1].id != 0)
			adj[p[i].id].push_back({p[i-1].id, dist});
	}
	sort(p, p+m-1, [](point& a, point& b) {
		return a.y < b.y;
	});
	for (int i = 1; i < m-1; i++) {
		int dist = p[i].y - p[i-1].y;
		if (p[i].id != 0)
			adj[p[i-1].id].push_back({p[i].id, dist});
		if (p[i-1].id != 0)
			adj[p[i].id].push_back({p[i-1].id, dist});
	}

	// Dijkstra's algorithm with priority queue
	int d[m];
	fill(d, d+m, INT_MAX);
	d[0] = 0;
	bool visited[m] = {};
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	pq.push({0, 0});
	while (!pq.empty()) {
		int u = pq.top().second;
		pq.pop();
		if (visited[u])
			continue;
		visited[u] = true;
		for (pii& edge: adj[u]) {
			int v = edge.first;
			int len = edge.second;
			if (!visited[v] && len + d[u] < d[v]) {
				d[v] = len + d[u];
				pq.push({d[v], v});
			}
		}
	}
	cout << d[m-1] << '\n';
	return 0;
}