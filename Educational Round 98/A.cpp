#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	int test;
	cin >> test;
	while (test--) {
		int x, y;
		cin >> x >> y;
		int ans = 0;
		ans += x + y;
		if (abs(x-y) > 1)
			ans += abs(x-y) - 1;
		cout << ans << '\n';
	}
	return 0;
}