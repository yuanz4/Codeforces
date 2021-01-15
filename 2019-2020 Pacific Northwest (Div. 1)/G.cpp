#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	int n;
	cin >> n;
	vector<vector<int>> v;
	unordered_map<char, int> mapping{{'h', 0}, {'v', 1}};
	char dir;
	int t, m, a;
	for (int i = 0; i < n; i++) {
		cin >> dir >> t >> m >> a;
		int d = mapping[dir];
		// time, start/end, direction
		v.push_back({t-a, 1, d});
		v.push_back({t-a+m, -1, d});
	}
	sort(v.begin(), v.end());
	ll ans = 0;
	int hcnt = 0, vcnt = 0;
	for (auto& i: v) {
		if (i[2] == 0) {
			// horizontal
			hcnt += i[1];
			if (i[1] > 0)
				ans += vcnt;
		} else {
			// vertical
			vcnt += i[1];
			if (i[1] > 0)
				ans += hcnt;
		}
	}
	cout << ans << '\n';
	return 0;
}