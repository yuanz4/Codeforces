#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	int a;
	cin >> a;
	while (a >= 10) {
		int b = 0;
		while (a) {
			b += a % 10;
			a /= 10;
		}
		a = b;
	}
	cout << a << '\n';
	return 0;
}