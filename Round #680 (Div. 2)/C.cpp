#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int mx = 1000;
int p[mx];
int c[mx];
int m;

void divide(int n) {
	m = 0;
	for (int i = 2; i <= sqrt(n); i++) {
		if (n % i == 0) {
			p[++m] = i;
			c[m] = 0;
			while (n % i == 0) {
				n /= i;
				c[m]++;
			}
		}
	}
	if (n > 1) {
		p[++m] = n;
		c[m] = 1;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	int test;
	cin >> test;
	while (test--) {
		ll P, Q;
		cin >> P >> Q;
		if (P % Q != 0)
			cout << P << '\n';
		else {
			divide(Q);
			ll ans = -1;
			for (int i = 1; i <= m; i++) {
				ll a = 0, cur = P;
				while (cur % p[i] == 0) {
					cur /= p[i];
					a++;
				}
				a -= c[i] - 1;
				cur = P;
				while (a) {
					cur /= p[i];
					a--;
				}
				ans = max(cur, ans);
			}
			cout << ans << '\n';
		}
	}
	return 0;
}