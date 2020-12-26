#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	int test;
	cin >> test;
	while (test--) {
		int n, m;
		cin >> n >> m;
		unordered_set<int> s;
		int a, b;
		for (int i = 0; i < n; i++) {
			cin >> a;
			s.insert(a);
		}
		bool ok = false;
		int ans = -1;
		for (int i = 0; i < m; i++) {
			cin >> b;
			if (s.count(b)) {
				ans = b;
				ok = true;
			}
		}
		if (!ok)
			cout << "NO" << '\n';
		else {
			cout << "YES" << '\n';
			cout << "1 " << ans << '\n';
		}
	}
	return 0;
}