#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	int n, m;
	cin >> n >> m;
	string s;
	cin >> s;
	int len = s.size();
	vector<string> grid(m);
	for (auto& i: grid)
		cin >> i;
	reverse(grid.begin(), grid.end());
	vector<int> state[m][n];
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			state[i][j].assign(len + 1, INT_MAX);
		}
	}
	state[0][0][0] = grid[0][0] - '0';
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < len + 1; k++) {
				if (state[i][j][k] != INT_MAX) {
					if (i + 1 < m) {
						int val = grid[i+1][j] - '0';
						state[i+1][j][k] = min(state[i+1][j][k], state[i][j][k] + val);
					}
					if (j + 1 < n) {
						int val = grid[i][j+1] - '0';
						state[i][j+1][k] = min(state[i][j+1][k], state[i][j][k] + val);
					}
					if (k != len) {
						int step = s[k] - '0';
						step++;
						if (i + step < m) {
							int val = grid[i+step][j] - '0';
							state[i+step][j][k+1] = min(state[i+step][j][k+1], state[i][j][k] + val);
						}
						if (j + step < n) {
							int val = grid[i][j+step] - '0';
							state[i][j+step][k+1] = min(state[i][j+step][k+1], state[i][j][k] + val);
						}
					}
				}
			}
		}
	}
	int ans = INT_MAX;
	for (int i = 0; i < len + 1; i++)
		ans = min(ans, state[m-1][n-1][i]);
	cout << ans << '\n';
	return 0;
}