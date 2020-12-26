#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	int test;
	cin >> test;
	while (test--) {
		int n, m, r, c;
		cin >> n >> m >> r >> c;
		int ans = 0;
		ans = max(r-1, n-r) + max(c-1, m-c);
		cout << ans << '\n';
	}
	return 0;
}