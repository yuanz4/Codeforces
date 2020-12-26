#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	int test;
	cin >> test;
	while (test--) {
		ll a, b, c, d;
		cin >> a >> b >> c >> d;
		if (a > b * c)
			cout << -1 << '\n';
		else {
			ll k = a / (b * d);
			ll damage = (k+1)*a-k*(k+1)/2*b*d;
			cout << damage << '\n'; 
		}
	}
	return 0;
}