#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct edge {
	int u, v, w;
	bool operator<(edge const& other) {
		return w < other.w;
	}
};

vector<int> p, height;

void build(int n) {
	p.resize(n);
	height.resize(n);
	for (int i = 0; i < n; i++) {
		p[i] = i;
		height[i] = 1;
	}
}

int get(int x) {
	if (x == p[x])
		return x;
	return p[x] = get(p[x]);
}

bool merge(int x, int y) {
	x = get(x);
	y = get(y);
	if (x == y)
		return false;
	if (height[x] < height[y])
		swap(x, y);
	p[y] = x;
	height[x] += height[y];
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	int n, m;
	cin >> n >> m;
	vector<edge> e, res;

	int u, v, w;
	for (int i = 0; i < m; i++) {
		cin >> u >> v >> w;
		u--, v--;
		e.push_back({u, v, w});
	}
	sort(e.begin(), e.end());

	int pos, count = 0;
	build(n);
	for (int i = m - 1; i >= 0; i--) {
		if (merge(e[i].u, e[i].v)) {
			count++;
			if (count == n - 1) {
				pos = i;
				break;
			}
		}
	}
	
	build(n);
	for (int i = pos; i < m; i++) {
		if (merge(e[i].u, e[i].v))
			res.push_back(e[i]);
	}

	sort(res.begin(), res.end());
	reverse(res.begin(), res.end());
	ll ans = 0;
	build(n);
	for (auto& i: res) {
		int sz1 = height[get(i.u)];
		int sz2 = height[get(i.v)];
		ans += 1ll * i.w * sz1 * sz2;
		merge(i.u, i.v);
	}
	cout << ans << '\n';
	return 0;
}