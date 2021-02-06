#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	int test;
	cin >> test;
	while (test--) {
		ll n, k;
		cin >> n >> k;
		k = (n + k - 1) / k * k;
		cout << (k + n - 1) / n << '\n';
	}
	return 0;
}