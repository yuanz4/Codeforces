#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	int n;
	cin >> n;
	double ans = 1e9;
	double x, y, z;
	for (int i = 0; i < n; i++) {
		cin >> x >> y >> z;
		ans = min(ans, sqrt(x*x+y*y+z*z));
	}
	cout << fixed << setprecision(3) << ans << '\n';
	return 0;
}