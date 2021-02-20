#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void fail() {
	cout << "N" << '\n';
	exit(0);
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	int n;
	cin >> n;
	int grid[10][10] = {};
	int d, l, r, c;
	for (int i = 0; i < n; i++) {
		cin >> d >> l >> r >> c;
		r--, c--;
		for (int j = 0; j < l; j++) {
			int x = r + j * d;
			int y = c + j * (1 - d);
			if (x >= 10 || y >= 10)
				fail();
			if (grid[x][y] == 1)
				fail();
			grid[x][y] = 1;
		}
	}
	cout << "Y" << '\n';
	return 0;
}