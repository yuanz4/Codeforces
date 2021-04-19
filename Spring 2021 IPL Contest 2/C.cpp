#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

vector<vector<int>> ans;
int node = 1;

void build(int cur, pii state);

void push(int cur, int w, pii left, pii right) {
	int l = 0, r = 0;
	if (left != pii{0, 0}) {
		l = node++;
		build(l, left);
	}
	if (right != pii{0, 0}) {
		r = node++;
		build(r, right);
	}
	ans.push_back({cur, w, l, r});
}

void build(int cur, pii state) {
	int a = state.first;
	int b = state.second;
	if (a == 0 && b % 2 == 0) {
		cout << -1 << '\n';
		exit(0);
	}
	if (b == 0) {
		a--;
		push(cur, 1, {a/2, 0}, {a-a/2, 0});
	} else {
		b--;
		if (b % 2 == 0)
			push(cur, 2, {a/2, b/2}, {a-a/2, b/2});
		else
			push(cur, 2, {(a+2)/2, b/2}, {a-(a+2)/2, b-b/2});
	}
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	int a, b;
	cin >> a >> b;
	build(node++, {a, b});
	sort(ans.begin(), ans.end());
	for (auto& i: ans)
		cout << i[1] << " " << i[2] << " " << i[3] << '\n';
	return 0;
}