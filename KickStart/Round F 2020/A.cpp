#include <bits/stdc++.h>
using namespace std;

int main() {
	int test;
	scanf("%d", &test);
	for (int t = 1; t <= test; t++) {
		printf("Case #%d:", t);
		int n, x;
		scanf("%d %d", &n, &x);
		int temp;
		vector<pair<int, int>> ret(n);
		for (int i = 0; i < n; i++) {
			scanf("%d", &temp);
			ret[i] = {temp/x+(temp%x!=0), i+1};
		}
		sort(ret.begin(), ret.end());
		for (int i = 0; i < n; i++)
			printf(" %d", ret[i].second);
		printf("\n");
	}
	return 0;
}