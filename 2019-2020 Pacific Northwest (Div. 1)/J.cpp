#include <bits/stdc++.h>
#define _USE_MATH_DEFINES
using namespace std;

typedef long long ll;
const double PI = atan(1) * 4;

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	int n;
	cin >> n;
	double t, s, a;
	vector<pair<double, double>> slope;
	double cur = 0;
	for (int i = 0; i < n; i++) {
		cin >> t >> s >> a;
		if (s != 0 && t / s < PI) {
			slope.push_back({a - t / s, s});
			slope.push_back({a, -2 * s});
			slope.push_back({a + t / s, s});
			slope.push_back({a - t / s + 2 * PI, s});
			slope.push_back({a + 2 * PI, -2 * s});
			slope.push_back({a + t / s + 2 * PI, s});
		} else {
			cur += t - PI * s;
			slope.push_back({a - PI, s});
			slope.push_back({a, -2 * s});
			slope.push_back({a + PI, 2 * s});
			slope.push_back({a + 2 * PI, -2 * s});
			slope.push_back({a + 3 * PI, s});
		}
	}
	sort(slope.begin(), slope.end());
	double ans = cur;
	double last_angle = slope[0].first;
	double last_slope = 0;
	for (auto& i: slope) {
		cur += last_slope * (i.first - last_angle);
		last_slope += i.second;
		last_angle = i.first;
		ans = max(ans, cur);
	}
	printf("%.6lf\n", ans);
	return 0;
}