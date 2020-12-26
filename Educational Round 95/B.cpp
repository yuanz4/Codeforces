#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	int test;
	scanf("%d", &test);
	while (test--) {
		int n;
		scanf("%d", &n);
		int a[n], l[n];
		for (int i = 0; i < n; i++)
			scanf("%d", &a[i]);
		for (int i = 0; i < n; i++)
			scanf("%d", &l[i]);
		vector<int> v;
		for (int i = 0; i < n; i++) {
			if (!l[i])
				v.push_back(a[i]);
		}
		sort(v.begin(), v.end(), greater<int>());
		int index = 0;
		for (int i = 0; i < n; i++) {
			if (l[i])
				printf("%d", a[i]);
			else
				printf("%d", v[index++]);
			if (i != n-1)
				printf(" ");
		}
		printf("\n");
	}
	return 0;
}