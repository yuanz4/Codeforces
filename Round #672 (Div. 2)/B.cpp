#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	int test;
	scanf("%d", &test);
	while (test--) {
		int n;
		scanf("%d", &n);
		int a[n];
		for (int i = 0; i < n; i++)
			scanf("%d", &a[i]);
		unordered_map<int, int> m;
		ll ret = 0;
		for (int i = 0; i < n; i++) {
			int cur = log2(a[i]);
			if (i && m.count(cur))
				ret += m[cur];
			m[cur]++;
		}
		printf("%lld\n", ret);
	}
	return 0;
}