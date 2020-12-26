#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	int test;
	cin >> test;
	while (test--) {
		int l, r;
		cin >> l >> r;
		if (2*l <= r)
			cout << l << " " << 2*l << '\n';
		else
			cout << "-1 -1" << '\n';
	}
	return 0;
}