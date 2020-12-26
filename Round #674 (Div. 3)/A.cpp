#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	int test;
	cin >> test;
	while (test--) {
		int n, x;
		cin >> n >> x;
		if (n <= 2)
			cout << 1 << '\n';
		else
			cout << (n-2)/x+((n-2)%x!=0)+1 << '\n';
	}
	return 0;
}