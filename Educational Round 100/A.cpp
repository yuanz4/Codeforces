#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	int test;
	cin >> test;
	while (test--) {
		int a, b, c;
		cin >> a >> b >> c;
		int sum = a + b + c;
		if (sum % 9 == 0 && (sum / 9 <= min({a, b, c})))
			cout << "YES" << '\n';
		else
			cout << "NO" << '\n';
	}
	return 0;
}