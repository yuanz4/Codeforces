#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	int test;
	cin >> test;
	while (test--) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		int x = a + b;
		int y = c + d;
		cout << max(x, y) << '\n';
	}
	return 0;
}