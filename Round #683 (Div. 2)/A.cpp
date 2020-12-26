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
		cout << n << '\n';
		for (int i = 1; i <= n; i++)
			cout << i << ' ';
		cout << '\n';
	}
	return 0;
}