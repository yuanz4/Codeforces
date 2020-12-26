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
		bool success = false;
		for (int i = 0; i < n-1; i++) {
			if (a[i] > a[i+1])
				continue;
			success = true;
			break;
		}
		if (success)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}