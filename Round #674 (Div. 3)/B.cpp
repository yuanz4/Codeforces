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
		int a, b, c, d;
		bool find = false;
		for (int i = 0; i < n; i++) {
			cin >> a >> b >> c >> d;
			if (b == c)
				find = true;
		}
		if (m % 2 != 0)
			cout << "NO" << '\n';
		else {
			if (find)
				cout << "YES" << '\n';
			else
				cout << "NO" << '\n';
		}
	}
	return 0;
}