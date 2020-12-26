#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	int test;
	cin >> test;
	while (test--) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		int x = abs(x1 - x2);
		int y = abs(y1 - y2);
		if (x == 0 || y == 0)
			cout << x + y << '\n';
		else
			cout << x + y + 2 << '\n';
	}
	return 0;
}