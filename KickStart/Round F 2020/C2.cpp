#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

vector<pii> neigh(int s, map<pii, bool>& m, pii p) {
	vector<pii> ret;
	if (p.second != 1) {
		pii cur = {p.first, p.second-1};
		if (m[cur])
			ret.push_back(cur);
	}
	if (p.second != p.first*2-1) {
		pii cur = {p.first, p.second+1};
		if (m[cur])
			ret.push_back(cur);
	}
	if (p.second % 2 == 0 && p.first != 1) {
		pii cur = {p.first-1, p.second-1};
		if (m[cur])
			ret.push_back(cur);
	} else if (p.second % 2 == 1 && p.first != s) {
		pii cur = {p.first+1, p.second+1};
		if (m[cur])
			ret.push_back(cur);
	}
	return ret;
}

int dfs(int s, map<pii, bool>& m, bool first, pii a, pii b) {
	vector<pii> an = neigh(s, m, a), bn = neigh(s, m, b);
	if (an.empty() && bn.empty())
		return 0;
	if (first) {
		if (an.empty())
			return dfs(s, m, !first, a, b);
		int ret = INT_MIN;
		for (pii& nei: an) {
			m[nei] = false;
			ret = max(ret, 1+dfs(s, m, !first, nei, b));
			m[nei] = true;
		}
		return ret;
	}
	if (bn.empty())
		return dfs(s, m, !first, a, b);
	int ret = INT_MAX;
	for (pii& nei: bn) {
		m[nei] = false;
		ret = min(ret, -1+dfs(s, m, !first, a, nei));
		m[nei] = true;
	}
	return ret;
}

int main() {
	int test;
	scanf("%d", &test);
	for (int t = 1; t <= test; t++) {
		int s, ra, pa, rb, pb, c;
		cin >> s >> ra >> pa >> rb >> pb >> c;
		map<pii, bool> m;
		for (int i = 1; i <= s; i++) {
			for (int j = 1; j <= i*2-1; j++) {
				m[{i, j}] = true;
			}
		}
		m[{ra, pa}] = false;
		m[{rb, pb}] = false;
		int r, p;
		for (int i = 0; i < c; i++) {
			scanf("%d %d", &r, &p);
			m[{r, p}] = false;
		}
		int ret = dfs(s, m, true, {ra, pa}, {rb, pb});
		printf("Case #%d: %d\n", t, ret);
	}
	return 0;
}