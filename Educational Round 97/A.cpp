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
		int a = l * 2;
		if (a > r)
			cout << "YES" << '\n';
		else
			cout << "NO" << '\n';
	}
	return 0;
}