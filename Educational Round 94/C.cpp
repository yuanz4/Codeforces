#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	int test;
	scanf("%d", &test);
	while (test--) {
		string s;
		ll x;
		cin >> s >> x;
		ll n = s.size();
		string ret(n, '1');
		for (int i = 0; i < n; i++) {
			if (s[i] == '0') {
				if (i >= x)
					ret[i-x] = '0';
				if (i+x < n)
					ret[i+x] = '0';
			}
		}
		for (int i = 0; i < n; i++) {
			if (s[i] == '1') {
				bool one = false;
				if (i >= x)
					one |= ret[i-x] == '1';
				if (i+x < n)
					one |= ret[i+x] == '1';
				if (one == false) {
					cout << -1 << endl;
					goto next;
				}
			}
		}
		cout << ret << endl;
		next:;
	}
	return 0;
}