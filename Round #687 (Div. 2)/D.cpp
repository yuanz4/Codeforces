#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; i++)
		cin >> a[i];
	map<int, int> level, index;
	bool three = false;
	for (int i = n-1; i >= 0; i--) {
		int zero = __builtin_clz(a[i]);
		if (!index.count(zero))
			index[zero] = i;
		level[zero]++;
		if (level[zero] == 3) {
			three = true;
			break;
		}
	}
	if (three) {
		cout << 1 << '\n';
		return 0;
	}
	int before = -1;
	int step = 0;
	int ans = n;
	for (auto& p: index) {
		int zero = p.first;
		int i = p.second;
		step++;
		int first, second, pre;
		if (before == -1 || __builtin_clz(before) < zero) {
			if (level[zero] == 1) {
				before = -1;
				step = 0;
				continue;
			}
			first = a[i];
			second = a[i-1];
			pre = i - 2;
		} else {
			if (level[zero] == 2) {
				ans = min(ans, step);
				before = -1;
				step = 1;
				first = a[i];
				second = a[i-1];
				pre = i - 2;
			} else {
				first = before;
				second = a[i];
				pre = i - 1;
			}
		}
		int high = first ^ second;
		if (pre >= 0) {
			int low = second ^ a[pre];
			if (high < a[pre] || low > first) {
				ans = min(ans, step);
				before = -1;
				step = 0;
			} else
				before = high;
		}
	}
	if (ans == n)
		cout << -1 << '\n';
	else
		cout << ans << '\n';
	return 0;
}