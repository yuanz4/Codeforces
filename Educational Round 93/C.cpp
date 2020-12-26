#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	int test;
	scanf("%d", &test);
	while (test--) {
		int n;
		scanf("%d", &n);
		string s;
		cin >> s;
		int a[n];
		for (int i = 0; i < n; i++)
			a[i] = s[i] - '0';
		ll ret = 0;
		unordered_map<int, int> m;
		m[0] = 1;
		int pre = 0;
		for (int i = 0; i < n; i++) {
			pre += a[i];
			int x = pre - i - 1;
			if (m.count(x))
				ret += m[x];
			m[x]++;
		}
		printf("%lld\n", ret);
	}
	return 0;
}