#include <bits/stdc++.h>
using namespace std;

int main() {
	int test;
	scanf("%d", &test);
	while (test--) {
		int n;
		scanf("%d", &n);
		int a[n];
		for (int i = 0; i < n; i++)
			scanf("%d", &a[i]);
		if (a[0]+a[1] <= a[n-1])
			printf("1 2 %d\n", n);
		else
			printf("-1\n");
	}
	return 0;
}