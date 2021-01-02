#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	int test;
	cin >> test;
	while (test--) {
		string s;
		cin >> s;
		int n = s.size();
		if (n == 1) {
			cout << 0 << '\n';
			continue;
		} else if (n == 2) {
			cout << (s[0] == s[1]) << '\n';
			continue;
		}
		int count = 0;
		int r = 0;
		for (int i = 0; i < n-2; i++) {
			if (s[i] == s[i+1] && s[i] == s[i+2]) {
				s[i+1] = r + '0';
				r = (r + 1) % 10;
				s[i+2] = r + '0';
				r = (r + 1) % 10;
				count += 2;
			} else if (s[i+1] == s[i+2] || s[i] == s[i+2]) {
				s[i+2] = r + '0';
				r = (r + 1) % 10;
				count++;
			} else if (s[i] == s[i+1]) {
				s[i+1] = r + '0';
				r = (r + 1) % 10;
				count++;
			}
		}
		cout << count << '\n';
	}
	return 0;
}