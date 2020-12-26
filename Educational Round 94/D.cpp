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
		for (int& i: a) {
			scanf("%d", &i);
			i--;
		}
		vector<int> freq(n*n, 0);
		ll total = 0;
		for (int k = 0; k < n; k++) {
			int j = k - 1;
			for (int i = 0; i < j; i++)
				freq[a[i]*n+a[j]]++;
			for (int l = k+1; l < n; l++)
				total += freq[a[k]*n+a[l]];
		}
		cout << total << endl;
	}
	return 0;
}