#include <bits/stdc++.h>
using namespace std;

int main() {
	int test;
	scanf("%d", &test);
	for (int t = 1; t <= test; t++) {
		int n, k;
		scanf("%d %d", &n, &k);
		int s, e;
		vector<pair<int, int>> a(n);
		for (int i = 0; i < n; i++) {
			scanf("%d %d", &s, &e);
			a[i] = {s, e};
		}
		sort(a.begin(), a.end());
		int i = 0, ret = 0;
		s = -1, e = -1;
		int end = -1;
		for (int i = 0; i < n; i++) {
			s = a[i].first;
			e = a[i].second;
			end = max(end, s);
			while (end < e) {
				end += k;
				ret++;
			}
		}
		printf("Case #%d: %d\n", t, ret);
	}
	return 0;
}