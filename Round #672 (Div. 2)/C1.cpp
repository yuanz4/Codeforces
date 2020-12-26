#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	int test;
	scanf("%d", &test);
	while (test--) {
		int n, q;
		scanf("%d %d", &n, &q);
		ll a[n];
		for (int i = 0; i < n; i++)
			scanf("%lld", &a[i]);
		ll add[n] = {};
		add[0] = a[0];
		ll sub[n];
		fill(sub, sub+n+1, INT_MIN);
		for (int i = 1; i < n; i++) {
			add[i] = max(add[i-1], a[i]);
			add[i] = max(add[i], sub[i-1]+a[i]);
			sub[i] = max(sub[i-1], add[i-1]-a[i]);
		}
		printf("%lld\n", add[n-1]);
	}
	return 0;
}