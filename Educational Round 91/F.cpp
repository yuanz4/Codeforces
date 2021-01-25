#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define left(v) (v << 1)
#define right(v) ((v << 1) + 1)
const int mod = 998244353;
const int MAX = 5e5 + 7;

int add(int a, int b) {
	a += b;
	if (a >= mod)
		a -= mod;
	return a;
}

int mul(int a, int b) {
	return 1ll * a * b % mod;
}

struct node {
	// XOOX, XOOO, OOOX, OOOO
	int val[4];
	int len;
} t[MAX*4];
vector<int> c;

void merge_node(node& l, node& r, node& v, int a, int b) {
	v.val[0] = mul(l.val[1], r.val[2]);
	v.val[1] = mul(l.val[1], r.val[3]);
	v.val[2] = mul(l.val[3], r.val[2]);
	v.val[3] = mul(l.val[3], r.val[3]);
	if (a == 1) {
		int mid = 19 - (a * 10 + b);
		if (l.len != 1 && r.len != 1)
			v.val[0] = add(v.val[0], mul(mul(l.val[0], r.val[0]), mid));
		if (l.len != 1)
			v.val[1] = add(v.val[1], mul(mul(l.val[0], r.val[1]), mid));
		if (r.len != 1)
			v.val[2] = add(v.val[2], mul(mul(l.val[2], r.val[0]), mid));
		v.val[3] = add(v.val[3], mul(mul(l.val[2], r.val[1]), mid));
	}
}

void build(int v, int tl, int tr) {
	t[v].len = tr - tl + 1;
	if (tl == tr) {
		t[v].val[0] = t[v].val[1] = t[v].val[2] = 1;
		t[v].val[3] = c[tl] + 1;
		return;
	}
	int tm = (tl + tr) / 2;
	build(left(v), tl, tm);
	build(right(v), tm+1, tr);
	merge_node(t[left(v)], t[right(v)], t[v], c[tm], c[tm+1]);
}

void update(int v, int tl, int tr, int pos, int val) {
	if (tl == tr) {
		c[tl] = val;
		t[v].val[3] = val + 1;
		return;
	}
	int tm = (tl + tr) / 2;
	if (pos <= tm)
		update(left(v), tl, tm, pos, val);
	else
		update(right(v), tm+1, tr, pos, val);
	merge_node(t[left(v)], t[right(v)], t[v], c[tm], c[tm+1]);
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	int n, m;
	cin >> n >> m;
	string s;
	cin >> s;
	c.resize(n);
	for (int i = 0; i < n; i++)
		c[i] = s[i] - '0';
	build(1, 0, n-1);
	while (m--) {
		int x, d;
		cin >> x >> d;
		x--;
		update(1, 0, n-1, x, d);
		cout << t[1].val[3] << '\n';
	}
	return 0;
}