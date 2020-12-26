#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	int test;
	cin >> test;
	while (test--) {
		int x;
		cin >> x;
		int n = sqrt(x*2);
		while (n*(n+1)/2 < x)
			n++;
		int diff = n*(n+1)/2-x;
		int ans = n;
		if (diff == 1)
			ans++;
		cout << ans << '\n';
	}
	return 0;
}