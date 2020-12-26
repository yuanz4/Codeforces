#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	int test;
	cin >> test;
	while (test--) {
		int n, k;
		cin >> n >> k;
		int c[n];
		unordered_set<int> color;
		for (int i = 0; i < n; i++) {
			cin >> c[i];
			color.insert(c[i]);
		}
		int ans = n;
		for (auto& j: color) {
			int i = 0, cur = 0;
			while (i < n) {
				if (c[i] == j)
					i++;
				else {
					cur++;
					i += k;
				}
			}
			ans = min(ans, cur);
		}
		cout << ans << '\n';
	}
	return 0;
}