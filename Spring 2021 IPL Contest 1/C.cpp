#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	int n, a, b;
	cin >> n >> a >> b;
	double step[n+1] = {};
	int len = b - a + 1;
	double add = 1;
	if (a == 0) {
		add = len / (len - 1.0);
		len--;
		a++;
	}
	double pref[n+1] = {};
	for (int i = 1; i <= n; i++) {
		step[i] += add;
		int low = max(0, i - b - 1);
		int high = max(low, i - a);
		step[i] += (pref[high] - pref[low]) / len;
		pref[i] = pref[i-1] + step[i];
	}
	cout.precision(9);
    cout << fixed << step[n] << '\n';
	return 0;
}