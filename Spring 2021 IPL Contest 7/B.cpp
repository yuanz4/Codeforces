#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

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
		if (s[0] != '1' || s[n-1] != '1') {
			cout << "NO" << '\n';
			continue;
		}
		int zero = 0;
		for (auto& i: s)
			zero += i == '0';
		if (zero % 2) {
			cout << "NO" << '\n';
			continue;
		}
		cout << "YES" << '\n';
		string a, b;
		a += '(';
		b += '(';
		char br[2] = {'(', ')'};
		zero = 0;
		int one = 0;
		for (int i = 1; i < n - 1; i++) {
			if (s[i] == '0') {
				a += br[zero];
				b += br[1-zero];
				zero = 1 - zero;
			} else {
				a += br[one];
				b += br[one];
				one = 1 - one;
			}
		}
		a += ')';
		b += ')';
		cout << a << '\n';
		cout << b << '\n';
	}
	return 0;
}