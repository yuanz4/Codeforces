#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll take(ll f, ll cs, ll cw, ll s, ll w) {
	if (s > w)
		return take(f, cw, cs, w, s);
	if (cs * s >= f)
		return f / s;
	return cs + min((f-cs*s)/w, cw);
}

int main() {
	int test;
	scanf("%d", &test);
	while (test--) {
		ll p, f, cs, cw, s, w;
		cin >> p >> f >> cs >> cw >> s >> w;
		ll ret = 0;
		for (ll i = 0; i <= cs; i++) {
			if (i*s > p)
				break;
			ll j = min((p-i*s)/w, cw);
			ret = max(ret, i+j+take(f, cs-i, cw-j, s, w));
		}
		cout << ret << endl;
	}
	return 0;
}