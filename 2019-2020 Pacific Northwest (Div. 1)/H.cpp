#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const double PI = atan(1) * 4;

double fix(double angle) {
	if (angle < 0)
		angle += PI;
	return angle;
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	int n;
	cin >> n;
	int x[n], y[n];
	for (int i = 0; i < n; i++)
		cin >> x[i] >> y[i];
	int next[n][n];
	double angle[n][n];
	for (int i = 0; i < n; i++) {
		vector<pair<double, int>> p;
		for (int j = 0; j < n; j++) {
			if (j != i) {
				double xd = x[j] - x[i];
				double yd = y[j] - y[i];
				if (yd < 0 || (yd == 0 && xd < 0)) {
					xd = -xd;
					yd = -yd;
				}
				p.push_back({atan2(yd, xd), j});
			}
		}
		sort(p.begin(), p.end());
		int m = p.size();
		for (int j = 0; j < m; j++) {
			next[i][p[j].second] = p[(j+1)%m].second;
			angle[i][p[j].second] = fix(p[(j+1)%m].first - p[j].first);
		}
	}
	bool visited[n][n] = {};
	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i != j && !visited[i][j]) {
				int cnt[n] = {};
				int ii = i;
				int jj = j;
				double total = 0;
				while (true) {
					cnt[ii]++;
					visited[ii][jj] = true;
					total += angle[ii][jj];
					int kk = next[ii][jj];
					jj = ii;
					ii = kk;
					if (ii == i && jj == j && total >= 1.9 * PI)
						break;
				}
				for (auto& i: cnt)
					ans = max(ans, i);
			}
		}
	}
	cout << ans << '\n';
	return 0;
}