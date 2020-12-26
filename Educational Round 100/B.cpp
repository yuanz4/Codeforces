#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	int test;
	cin >> test;
	while (test--) {
		int n;
		cin >> n;
		int a[n];
		for (int i = 0; i < n; i++)
			cin >> a[i];
		for (int i = 0; i < n; i++) {
			int bit = log2(a[i]);
			int low = 1 << bit;
			cout << low << '\n';
		}
		cout << '\n';
	}
	return 0;
}


