#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
typedef long long ll;
typedef pair<int, int> pii;

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	int test;
	cin >> test;
	while (test--) {
		int n;
		cin >> n;
		string a[n];
		for (int i = 0; i < n; i++)
			cin >> a[i];
		vector<vector<pii>> nums(10);
		vector<vector<int>> bound(10);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				int cur = a[i][j] - '0';
				nums[cur].push_back({i, j});
				if (bound[cur].empty())
					bound[cur] = {i, i, j, j};
				bound[cur][0] = min(bound[cur][0], i);
				bound[cur][1] = max(bound[cur][1], i);
				bound[cur][2] = min(bound[cur][2], j);
				bound[cur][3] = max(bound[cur][3], j);
			}
		}
		int res[10];
		for (int i = 0; i < 10; i++) {
			int ans = 0;
			if (nums[i].size() < 2) {
				res[i] = 0;
				continue;
			}
			for (auto& j: nums[i]) {
				int hor = max(j.x, n-1-j.x);
				int ver = max(bound[i][3]-j.y, j.y-bound[i][2]);
				ans = max(ans, hor * ver);
				hor = max(bound[i][1]-j.x, j.x-bound[i][0]);
				ver = max(j.y, n-1-j.y);
				ans = max(ans, hor * ver);
			}
			res[i] = ans;
		}
		for (int i = 0; i < 10; i++)
			cout << res[i] << ' ';
		cout << '\n';
	}
	return 0;
}