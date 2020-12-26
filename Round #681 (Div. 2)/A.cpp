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
		for (int i = n; i < 2*n; i++) {
			cout << i*2 << ' ';
		}
		cout << '\n';
	}
	return 0;
}