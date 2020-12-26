#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	int test;
	cin >> test;
	while (test--) {
		ll a, b;
		cin >> a >> b;
		string s;
		cin >> s;
		int n = s.size();
		int i = 0, j = n-1;
		while (s[i] == '0') {
			i++;
		}
		while (s[j] == '0') {
			j--;
		}
		multiset<int> len;
		ll ans = 0;
		for (int k = i; k <= j; k++) {
			char c = s[k];
			int r = k;
			while (r < j && s[r+1] == c) {
				r++;
			}
			if (c == '0')
				len.insert(r-k+1);
			else
				ans += a;
			k = r;
		}
		ll cur = ans;
		for (auto& i: len) {
			cur -= a;
			cur += i * b;
			ans = min(ans, cur);
		}
		cout << ans << '\n';
	}
	return 0;
}