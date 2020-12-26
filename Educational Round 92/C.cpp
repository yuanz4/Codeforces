#include <bits/stdc++.h>
using namespace std;

int solve(string& s, int x, int y) {
	int ret = 0;
	for (auto& c: s) {
		if (c-'0' == x) {
			ret++;
			swap(x, y);
		}
	}
	if (x != y && ret % 2 == 1)
		ret--;
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	int test;
	cin >> test;
	while (test--) {
		string s;
		cin >> s;
		int ans = 0;
		for (int x = 0; x < 10; x++) {
			for (int y = 0; y < 10; y++) {
				ans = max(ans, solve(s, x, y));
			}
		}
		cout << s.size() - ans << '\n';
	}
	return 0;
}