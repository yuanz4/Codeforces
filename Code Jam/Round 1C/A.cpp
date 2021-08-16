#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	int test;
	cin >> test;
	for (int t = 1; t <= test; t++) {
		cout << "Case #" << t << ": ";
		int n, k;
		cin >> n >> k;
		int a[n];
		for (int i = 0; i < n; i++)
			cin >> a[i];
		sort(a, a + n);
		multiset<int> one, two;
		int first = a[0] - 1;
		if (first > 0)
			one.insert(first);
		int last = k - a[n-1];
		if (last > 0)
			one.insert(last);
		for (int i = 1; i < n; i++) {
			int cur = a[i] - a[i-1] - 1;
			if (cur >= 2)
				two.insert(cur);
			if (cur > 0) {
				cur = (cur - 1) / 2 + 1;
				one.insert(cur);
			}
		}
		int remain = 2;
		int ans = 0;
		while (remain && one.size()) {
			auto last = one.end();
			last--;
			ans += *last;
			one.erase(last);
			remain--;
		}
		if (two.size())
			ans = max(ans, *prev(two.end()));
		cout << ans * 1.0 / k << '\n';
	}
	return 0;
}