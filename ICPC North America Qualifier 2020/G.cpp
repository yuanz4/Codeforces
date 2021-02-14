#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	int n;
	cin >> n;
	double k;
	cin >> k;
	double a[n+2];
	a[0] = a[n+1] = 0;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	double b[n+2];
	int left, right, add;
	if (n % 2 == 0) {
		left = n / 2;
		right = n / 2 + 1;
		add = 2;
	} else {
		left = right = n / 2 + 1;
		add = 1;
	}
	b[left] = b[right] = 0;
	left--, right++;
	while (left >= 0) {
		b[left] = b[right] = b[left+1] + add;
		add += 2;
		left--, right++;
	}
	double base = b[0];
	for (int i = 0; i <= n + 1; i++)
		b[i] = (base - b[i]) * k;
	double c[n+2];
	for (int i = 0; i <= n + 1; i++)
		c[i] = a[i] - b[i];
	vector<int> s;
	s.push_back(0);
	s.push_back(1);
	for (int i = 2; i <= n + 1; i++) {
		while (s.size() > 1) {
			int pre = s.back();
			int ppre = s[s.size()-2];
			double slope1 = (c[i] - c[pre]) / (i - pre);
			double slope2 = (c[pre] - c[ppre]) / (pre - ppre);
			if (slope1 >= slope2)
				s.pop_back();
			else
				break;
		}
		s.push_back(i);
	}
	for (int i = 1; i < s.size(); i++) {
		int left = s[i-1];
		int right = s[i];
		double slope = (c[right] - c[left]) / (right - left);
		for (int j = left + 1; j < right; j++)
			c[j] = c[left] + slope * (j - left);
	}
	double ans = 0;
	for (int i = 1; i <= n; i++) {
		c[i] += b[i];
		ans = max(ans, c[i]);
	}
	cout.precision(9);
	cout << fixed << ans << '\n';
	return 0;
}