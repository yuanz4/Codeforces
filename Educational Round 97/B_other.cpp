#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	int test;
	cin >> test;
	while (test--) {
		int n;
		cin >> n;
		string s;
		cin >> s;
		int ans = 0;
		for (int i = 0; i < n; i++)
			ans += s[i] == s[(i+1)%n];
		cout << ans / 2 << '\n';
	}
	return 0;
}