#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAX = 300000+7;

ll a[MAX];
int n;
ll ans;

void insert(int i) {
	if (i == 0 || i == n+1)
		return;
	if (a[i-1] < a[i] && a[i] > a[i+1])
		ans += a[i];
	if (a[i-1] > a[i] && a[i] < a[i+1])
		ans -= a[i];
}

void erase(int i) {
	if (i == 0 || i == n+1)
		return;
	if (a[i-1] > a[i] && a[i] < a[i+1])
		ans += a[i];
	if (a[i-1] < a[i] && a[i] > a[i+1])
		ans -= a[i];
}

int main() {
	int test;
	scanf("%d", &test);
	while (test--) {
		int q;
		scanf("%d %d", &n, &q);
		a[0] = -1;
		a[n+1] = -1;
		ans = 0;
		for (int i = 1; i <= n; i++)
			scanf("%lld", &a[i]);
		for (int i = 1; i <= n; i++)
			insert(i);
		printf("%lld\n", ans);
		while (q--) {
			int l, r;
			scanf("%d %d", &l, &r);
			erase(l-1);
			erase(l);
			erase(l+1);
			if (l != r) {
				if (r-1 > l+1)
					erase(r-1);
				if (r > l+1)
					erase(r);
				erase(r+1);
			}
			swap(a[l], a[r]);
			insert(l-1);
			insert(l);
			insert(l+1);
			if (l != r) {
				if (r-1 > l+1)
					insert(r-1);
				if (r > l+1)
					insert(r);
				insert(r+1);
			}
			printf("%lld\n", ans);
		}
	}
	return 0;
}