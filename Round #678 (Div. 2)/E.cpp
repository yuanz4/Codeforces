#include <bits/stdc++.h>
using namespace std;

#define left(v) (v << 1)
#define right(v) ((v << 1) + 1)
const int MAX = 1e5+5;
int t[4*MAX];
int last[MAX]; 

int find(int v, int tl, int tr, int k) {
	if (tl == tr)
		return tl;
	int tm = (tl + tr) / 2;
	if (t[left(v)] < k)
		return find(left(v), tl, tm, k);
	return find(right(v), tm+1, tr, k);
}

void update(int v, int tl, int tr, int pos, int val) {
	if (tl == tr)
		t[v] = val;
	else {
		int tm = (tl + tr) / 2;
		if (pos <= tm)
			update(left(v), tl, tm, pos, val);
		else
			update(right(v), tm+1, tr, pos, val);
		t[v] = min(t[left(v)], t[right(v)]);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	int n;
	cin >> n;
	int max_MEX = n + 1;
	unordered_map<int, bool> m;
	int x;
	for (int i = 1; i <= n; i++) {
		cin >> x;
		int left_bound = last[x] + 1;
		if (left_bound < i)
			m[find(1, 1, max_MEX, left_bound)] = true;
		update(1, 1, n+1, x, i);
		last[x] = i;
	}
	for (int i = 1; i <= n+1; i++) {
		if (last[i] && last[i] != n)
			m[find(1, 1, max_MEX, last[i]+1)] = true;
	}
	m[find(1, 1, max_MEX, 1)] = true;
	for (int i = 1; ; i++) {
		if (!m[i]) {
			cout << i << '\n';
			break;
		}
	}
	return 0;
}