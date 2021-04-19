#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int gcd(int a, int b) {
	if (b == 0)
		return a;
	return gcd(b, a%b);
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	int test;
	cin >> test;
	while (test--) {
		int b, d;
		cin >> b >> d;
		int g = gcd(b, d);
		cout << 1ll * (b - 1) * g / d << '\n';
	}
	return 0;
}