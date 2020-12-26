#include <bits/stdc++.h>
using namespace std;

int main() {
	int test;
	scanf("%d", &test);
	for (int t = 1; t <= test; t++) {
		int n;
		scanf("%d", &n);
		int A[n];
		for (int& i: A)
			scanf("%d", &i);
		int num = A[1] - A[0];
		int count = 1;
		int ret = 2;
		for (int i = 1; i < n-1; i++) {
			int cur = A[i+1] - A[i];
			if (cur == num) {
				count++;
			} else {
				ret = max(ret, count+1);
				count = 1;
				num = cur;
			}
		}
		ret = max(ret, count+1);
		printf("Case #%d: %d\n", t, ret);
	}
	return 0;
}