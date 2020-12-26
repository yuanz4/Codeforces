#include <bits/stdc++.h>
using namespace std;

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
		int ones = 0;
		for (int i = 0; i < n; i++) {
			if (a[i] == 1)
				ones++;
			else
				break;
		}
		if (ones == n) {
			if (ones % 2 == 0)
				cout << "Second" << '\n';
			else
				cout << "First" << '\n';
		} else {
			if (ones % 2 == 0)
				cout << "First" << '\n';
			else
				cout << "Second" << '\n';
		}
	}
	return 0;
}