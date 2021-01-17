#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define left(v) (v + 1)
#define right(v, l, mid) (v + 2 * (mid - l + 1))
const int MAX = 5e5+7;

struct cache {
	int index = -1, version;
	int lhs, rhs;
	bool marked = false;
};

struct info {
	int inc = 0;
    info *l = NULL, *r = NULL;
    info(int inc) : inc(inc) {}
    info(int inc, info* l, info* r) : inc(inc), l(l), r(r) {}
};

cache t[2*MAX];
vector<info*> roots[MAX];

// --------------------------------------------------------------

void push_cache(int v) {
	if (t[v].marked) {
		int mhs = (t[v].lhs + t[v].rhs) / 2;
		t[left(v)] = {t[v].index, t[v].version, t[v].lhs, mhs, true};
		t[right(v, t[v].lhs, mhs)] = {t[v].index, t[v].version, mhs+1, t[v].rhs, true};
		t[v].marked = false;
	}
}

void update_cache(int v, int tl, int tr, int l, int r, cache cur) {
	if (l > r)
		return;
	if (l == tl && tr == r)
		t[v] = cur;
	else {
		push_cache(v);
		int tm = (tl + tr) / 2;
		cache left_cache{cur.index, cur.version, cur.lhs, min(cur.lhs+tm-l, cur.rhs), true};
		cache right_cache{cur.index, cur.version, max(cur.lhs, cur.lhs+tm-l+1), cur.rhs, true};
		update_cache(left(v), tl, tm, l, min(tm, r), left_cache);
		update_cache(right(v, tl, tm), tm+1, tr, max(l, tm+1), r, right_cache);
	}
}

cache get_cache(int v, int tl, int tr, int pos) {
	if (tl == tr)
		return t[v];
	push_cache(v);
	int tm = (tl + tr) / 2;
	if (pos <= tm)
		return get_cache(left(v), tl, tm, pos);
	return get_cache(right(v, tl, tm), tm+1, tr, pos);
}

// --------------------------------------------------------------

info* build_info(int tl, int tr, vector<int>& v) {
	if (tl == tr)
		return new info(v[tl]);
	int tm = (tl + tr) / 2;
	return new info(0, build_info(tl, tm, v), build_info(tm+1, tr, v));
}

info* update_info(info* v, int tl, int tr, int l, int r, int inc) {
	if (l > r)
		return v;
    if (l == tl && r == tr)
        return new info(v->inc+inc, v->l, v->r);
    int tm = (tl + tr) / 2;
    return new info(v->inc, update_info(v->l, tl, tm, l, min(tm, r), inc),
    	update_info(v->r, tm+1, tr, max(l, tm+1), r, inc));
}

int get_info(info* v, int tl, int tr, int pos) {
	if (tl == tr)
		return v->inc;
	int tm = (tl + tr) / 2;
	if (pos <= tm)
		return v->inc + get_info(v->l, tl, tm, pos);
	return v->inc + get_info(v->r, tm+1, tr, pos);
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	int n, m, q;
	cin >> n >> m >> q;
	int size[m];
	for (int i = 0; i < m; i++) {
		int s;
		cin >> s;
		vector<int> v(s);
		for (int j = 0; j < s; j++)
			cin >> v[j];
		size[i] = v.size();
		roots[i].push_back(build_info(0, size[i]-1, v));
	}
	while (q--) {
		int type;
		cin >> type;
		if (type == 1) {
			int i, p;
			cin >> i >> p;
			i--, p--;
			update_cache(1, 0, n-1, p, p+size[i]-1, {i, (int)roots[i].size()-1, 0, size[i]-1, true});
		} else if (type == 2) {
			int p;
			cin >> p;
			p--;
			cache cur = get_cache(1, 0, n-1, p);
			if (cur.index == -1) {
				cout << 0 << '\n';
				continue;
			}
			cout << get_info(roots[cur.index][cur.version], 0, size[cur.index]-1, cur.lhs) % 256 << '\n';
		} else {
			int i, l, r;
			cin >> i >> l >> r;
			i--, l--, r--;
			roots[i].push_back(update_info(roots[i].back(), 0, size[i]-1, l, r, 1));
		}
	}
	return 0;
}