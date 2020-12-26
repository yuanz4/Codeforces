#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	int test;
	cin >> test;
	while (test--) {
		int n, m;
		cin >> n >> m;
		int ans = 0;
		bool zero = false;
		int neg = 0;
		int smallest = INT_MAX;
		int temp;
		for (int i = 0; i < n*m; i++) {
			cin >> temp;
			if (temp == 0)
				zero = true;
			else if (temp < 0)
				neg++;
			smallest = min(smallest, abs(temp));
			ans += abs(temp);
		}
		if (!zero) {
			if (neg % 2 != 0)
				ans -= smallest * 2;
		}
		cout << ans << '\n';
	}
	return 0;
}