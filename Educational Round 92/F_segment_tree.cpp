#include <bits/stdc++.h>
using namespace std;

#define left(v) (v << 1)
#define right(v) ((v << 1) + 1)
#define r first
#define l second
#define all(v) v.begin(), v.end()

struct segtree {
	struct node {
		int add = 0, mx = -1;
	};
	int n;
	vector<node> t;

	segtree(int n) : n(n) {
		t.resize(4 * n);
	};

	void push(int v, int tl, int tr) {
		if (tl != tr) {
			t[left(v)].add += t[v].add;
			t[right(v)].add += t[v].add;
		}
		t[v].mx += t[v].add;
		t[v].add = 0;
	}

	void update(int v, int tl, int tr, int pos, int val) {
		push(v, tl, tr);
		if (tl == tr) {
			t[v].mx = val;
			return;
		}
		int tm = (tl + tr) / 2;
		if (pos <= tm)
			update(left(v), tl, tm, pos, val);
		else
			update(right(v), tm+1, tr, pos, val);
		t[v].mx = max(t[left(v)].mx, t[right(v)].mx);
	}

	int get(int v, int tl, int tr, int l, int r) {
		push(v, tl, tr);
		if (l > r)
			return -1;
		if (l == tl && r == tr)
			return t[v].mx;
		int tm = (tl + tr) / 2;
		int ret1 = get(left(v), tl, tm, l, min(tm, r));
		int ret2 = get(right(v), tm+1, tr, max(l, tm+1), r);
		return max(ret1, ret2);
	}

	void add(int v, int tl, int tr, int l, int r, int val) {
		push(v, tl, tr);
		if (l > r)
			return;
		if (l == tl && r == tr) {
			t[v].add += val;
			push(v, tl, tr);
			return;
		}
		int tm = (tl + tr) / 2;
		add(left(v), tl, tm, l, min(tm, r), val);
		add(right(v), tm+1, tr, max(l, tm+1), r, val);
		t[v].mx = max(t[left(v)].mx, t[right(v)].mx);
	}

	void update(int pos, int val) {
		return update(1, 0, n-1, pos, val);
	}

	int get(int l, int r) {
		return get(1, 0, n-1, l, r);
	}

	void add(int l, int r, int val) {
		return add(1, 0, n-1, l, r, val);
	}
};


int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	int n;
	cin >> n;
	vector<pair<int, int>> a[2];
	int x, y, t;
	for (int i = 0; i < n; i++) {
		cin >> x >> y >> t;
		t--;
		a[t].push_back({y, x});
	}
	int n1 = a[0].size();
	int n2 = a[1].size();
	for (int i = 0; i < 2; i++)
		sort(all(a[i]));
	segtree t1(n1 + 1), t2(n2 + 1);
	t1.update(0, 0);
	t2.update(0, 0);
	int ans = 0;
	for (int i = 0, j = 0; i + j < n;) {
		if (i != n1 && (j == n2 || a[0][i].r < a[1][j].r)) {
			int pos = upper_bound(all(a[1]), make_pair(a[0][i].l, 0))
				- a[1].begin();
			int cur = t2.get(0, pos) + 1;
			ans = max(ans, cur);
			t1.update(i + 1, cur);
			t2.add(0, pos, 1);
			i++;
		} else {
			int pos = upper_bound(all(a[0]), make_pair(a[1][j].l, 0))
				- a[0].begin();
			int cur = t1.get(0, pos) + 1;
			ans = max(ans, cur);
			t2.update(j + 1, cur);
			t1.add(0, pos, 1);
			j++;
		}
	}
	cout << ans << '\n';
	return 0;
}