#include <bits/stdc++.h>
using namespace std;

#define MAX 200007
typedef long long ll;

int a[MAX];
int d[2][MAX];
int n;

int dfs(int p, int cur) {
	if (d[p][cur] != -1)
		return d[p][cur];
	if (cur >= n)
		return 0;
	if (p == 0) {
		int skip = 0;
		if (a[cur] == 1)
			skip++;
		d[p][cur] = skip + dfs(1-p, cur+1);
		if (cur != n-1) {
			if (a[cur+1] == 1)
				skip++;
			d[p][cur] = min(d[p][cur], skip + dfs(1-p, cur+2));
		}
	} else {
		d[p][cur] = dfs(1-p, cur+1);
		if (cur != n-1)
			d[p][cur] = min(d[p][cur], dfs(1-p, cur+2));
	}
	return d[p][cur];
}

int main() {
	int test;
	scanf("%d", &test);
	while (test--) {
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
			scanf("%d", &a[i]);
		memset(d, -1, sizeof(d));
		int ret = dfs(0, 0);
		printf("%d\n", ret);
	}
	return 0;
}