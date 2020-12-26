#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	int test;
	cin >> test;
	while (test--) {
		ll n;
		cin >> n;
		while (true) {
			ll cur = n;
			bool ok = true;
			while (cur) {
				int i = cur % 10;
				if (i && n % i != 0) {
					ok = false;
					break;
				}
				cur /= 10;
			}
			if (ok) {
				cout << n << '\n';
				break;
			}
			n++;
		}
	}
	return 0;
}