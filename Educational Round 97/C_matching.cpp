#include <bits/stdc++.h>
using namespace std;

const int inf = 0x3f3f3f3f, MAXN = 200;
const int N = MAXN*3+7, M = 2*(2*MAXN+3)*MAXN+7;
int head[N], ver[M], edge[M], Next[M], cost[M];
int v[N], incf[N], pre[N], d[N];
int s, t, tot, maxflow, ans;

void add(int x, int y, int z, int c) {
	ver[++tot] = y, edge[tot] = z, cost[tot] = c, Next[tot] = head[x], head[x] = tot;
	ver[++tot] = x, edge[tot] = 0, cost[tot] = -c, Next[tot] = head[y], head[y] = tot;
}

bool spfa() {
	memset(v, 0, sizeof(v));
	memset(d, 0x3f, sizeof(d));
	queue<int> q;
	q.push(s);
	d[s] = 0;
	v[s] = 1;
	incf[s] = inf;
	while (q.size()) {
		int x = q.front();
		q.pop();
		v[x] = 0;
		for (int i = head[x]; i; i = Next[i]) {
			if (edge[i]) {
				int y = ver[i];
				if (d[y] > d[x] + cost[i]) {
					d[y] = d[x] + cost[i];
					incf[y] = min(incf[x], edge[i]);
					pre[y] = i;
					if (!v[y]) {
						v[y] = 1;
						q.push(y);
					}
				}
			}
		}
	}
	if (d[t] == inf)
		return false;
	return true;
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
	ans += d[t] * incf[t];
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	int test;
	cin >> test;
	while (test--) {
		int n;
		cin >> n;
		int time[n];
		for (int i = 0; i < n; i++)
			cin >> time[i];
		s = 0, t = 3*n+1;
    	tot = 1;
    	maxflow = 0;
    	ans = 0;
    	memset(head, 0, sizeof(head));
    	for (int i = 1; i <= n; i++) {
    		add(s, i, 1, 0);
    		for (int j = 1; j <= 2*n; j++)
    			add(i, n+j, 1, abs(time[i-1]-j));
    	}
		for (int j = 1; j <= 2*n; j++)
			add(n+j, t, 1, 0);
		while (spfa())
    		update();
    	cout << ans << '\n';
	}
	return 0;
}