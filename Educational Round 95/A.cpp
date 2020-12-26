#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	int test;
	scanf("%d", &test);
	while (test--) {
		ll x, y, k;
		cin >> x >> y >> k;
		ll sticks = k * y + k;
		ll ret = (sticks-1) / (x-1) + k;
		if ((sticks-1) % (x-1))
			ret++;
		printf("%lld\n", ret);
	}
	return 0;
}