#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	int test;
	cin >> test;
	while (test--) {
		ll a, b, c;
		cin >> a >> b >> c;
		cout << a+b+c-1 << endl;
	}
	return 0;
}