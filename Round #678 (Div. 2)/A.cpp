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
		int a;
		ll sum = 0;
		for (int i = 0; i < n; i++) {
			cin >> a;
			sum += a;
		}
		if (sum == m)
			cout << "YES" << '\n';
		else
			cout << "NO" << '\n';
	}
	return 0;
}