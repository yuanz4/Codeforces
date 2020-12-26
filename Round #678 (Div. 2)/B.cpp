#include <bits/stdc++.h>
using namespace std;

bool prime(int p) {
	if (p == 1)
		return false;
	for (int i = 2; i*i <= p; i++) {
		if (p % i == 0)
			return false;
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	int test;
	cin >> test;
	while (test--) {
		int n;
		cin >> n;
		int a[n];
		for (int i = 0; i < n-1; i++)
			a[i] = 1;
		int last;
		for (last = 1; last < 100000; last++) {
			if (!prime(last) && prime(last+n-1))
				break;
		}
		a[n-1] = last;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (j)
					cout << ' ';
				cout << a[(i+j)%n];
			}
			cout << '\n';
		}
	}
	return 0;
}