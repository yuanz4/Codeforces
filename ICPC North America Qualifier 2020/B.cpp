#include <bits/stdc++.h>
using namespace std;

#define EPS DBL_EPSILON
#define sq(x) (x * x)
typedef long long ll;
const double PI = atan(1) * 4;

struct circle {
	int x, y, r;
};

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	int n;
	cin >> n;
	vector<circle> info(n);
	vector<vector<pair<double, double>>> remove(n);
	vector<bool> hidden(n);
	int x2, y2, r2;
	for (int i = 0; i < n; i++) {
		cin >> x2 >> y2 >> r2;
		info[i] = {x2, y2, r2};
		// place old circle at origin
		for (int j = 0; j < i; j++) {
			if (hidden[j])
				continue;
			int x1 = info[j].x;
			int y1 = info[j].y;
			int r1 = info[j].r;
			if (x1 == x2 && y1 == y2) {
				if (r2 >= r1)
					hidden[j] = true;
			} else {
				int x = x2 - x1;
				int y = y2 - y1;
				double dist = sqrt(sq(x) + sq(y));
				double a = -2 * x;
				double b = -2 * y;
				double c = sq(x) + sq(y) + sq(r1) - sq(r2);
				double ab = sq(a) + sq(b);
				double x0 = -a * c / ab;
				double y0 = -b * c / ab;
				if (sq(c) > sq(r1) * ab) {
					// 0 points
					if (dist > r1 + r2 || r1 > r2)
						continue;
					hidden[j] = true;
				} else if (abs(sq(c) - sq(r1) * ab) < EPS) {
					// 1 points
					if (abs(r1 + r2 - dist) < EPS || r1 > r2)
						continue;
					hidden[j] = true;
				} else {
					// 2 points
					double d = sq(r1) - sq(c) / ab;
					double mult = sqrt(d / ab);
					double ax = x0 + b * mult;
				    double bx = x0 - b * mult;
				    double ay = y0 - a * mult;
				    double by = y0 + a * mult;
				    double center = atan2(y, x);
				    vector<double> angle{atan2(ay, ax), atan2(by, bx)};
				    for (auto& k: angle) {
				    	double first = center, second = k;
				    	for (int l = 0; l < 2; l++) {
					    	if (first > second)
					    		second += 2 * PI;
				    		if (second - first < PI) {
				    			if (second > PI) {
				    				remove[j].push_back({first, PI});
				    				remove[j].push_back({-PI, second-2*PI});
				    			} else
					    			remove[j].push_back({first, second});
					    		break;
				    		}
					    	first = k, second = center;
				    	}
				    }
				}
			}
		}
	}
	double ans = 0;
	for (int i = 0; i < n; i++) {
		if (hidden[i])
			continue;
		// (-PI, PI]
		double total = 2 * PI;
		sort(remove[i].begin(), remove[i].end());
		double start = -PI, end = -PI;
		for (auto& j: remove[i]) {
			if (j.first > end) {
				total -= end - start;
				start = j.first;
				end = j.second;
			} else
				end = max(end, j.second);
		}
		total -= end - start;
		ans += total * info[i].r;
	}
	cout.precision(9);
	cout << fixed << ans << '\n';
	return 0;
}