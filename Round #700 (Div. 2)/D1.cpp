#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct info {
	int val, len;
};

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; i++)
		cin >> a[i];
	vector<info> b;
	for (int i = 0; i < n; i++) {
		int r = i;
		while (r + 1 < n && a[i] == a[r + 1])
			r++;
		int len = r - i + 1;
		b.push_back({a[i], len});
		i = r;
	}
	int m = b.size();
	int last = 0;
	int ans = 0;
	unordered_set<int> alter;
	for (int i = 0; i < m; i++) {
		int cur = b[i].val;
		if (b[i].len != 1) {
			ans += 1;
			if (!alter.count(cur) || alter.size() > 1)
				ans += 1;
			alter.clear();
			alter.insert(cur);
		} else {
			ans += 1;
			if (!alter.count(cur) || alter.size() > 1)
				alter.insert(last);
		}
		last = cur;
	}
	cout << ans << '\n';
	return 0;
}