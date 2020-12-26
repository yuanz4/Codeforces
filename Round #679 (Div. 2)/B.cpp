#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	int test;
	cin >> test;
	while (test--) {
		int n, m;
		cin >> n >> m;
		int r[n][m];
		unordered_map<int, int> mapping;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> r[i][j];
				if (j == 0)
					mapping[r[i][j]] = i;
			}
		}
		int first = r[0][0], index;
		int c[m][n];
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				cin >> c[i][j];
				if (c[i][j] == first)
					index = i;
			}
		}
		for (int i = 0; i < n; i++) {
			int cur = c[index][i];
			for (int j = 0; j < m; j++) {
				if (j)
					cout << ' ';
				cout << r[mapping[cur]][j];
			}
			cout << '\n';
		}
	}
	return 0;
}