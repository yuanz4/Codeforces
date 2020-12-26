#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	int test;
	cin >> test;
	while (test--) {
		int n, m;
		cin >> n >> m;
		int a[n], b[m];
		unordered_set<int> s;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			s.insert(a[i]);
		}
		int ans = 0;
		for (int i = 0; i < m; i++) {
			cin >> b[i];
			if (s.count(b[i]))
				ans++;
		}
		cout << ans << '\n';
	}
	return 0;
}