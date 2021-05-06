#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	int m, n;
	cin >> m >> n;
	string g[m];
	for (int i = 0; i < m; i++)
		cin >> g[i];
	int count = 0;
	pair<int, int> cur{0, 0};
	while (true) {
		set<pair<int, pair<int, int>>> s;
		int x = cur.first;
		int y = cur.second;
		if (g[x][y] == '*')
			count++;
		for (int i = x; i < m; i++) {
			for (int j = y; j < n; j++) {
				if (i == x && j == y)
					continue;
				if (g[i][j] == '*') {
					int dist = i - x + j - y;
					s.insert({dist, {i, j}});
				}
			}
		}
		if (s.empty())
			break;
		cur = s.begin()->second;
	}
	cout << count << '\n';
	return 0;
}