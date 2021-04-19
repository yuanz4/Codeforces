#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	int test;
	cin >> test;
	while (test--) {
		int n, k;
		cin >> n >> k;
		string s;
		cin >> s;
		int i = 0;
		for (int i = 0; i < n; i++) {
			if (!k) {
				if (i >= (n+1)/2)
					cout << "NO" << '\n';
				else
					cout << "YES" << '\n';
				break;
			}
			if (s[i] == s[n-i-1])
				k--;
			else {
				cout << "NO" << '\n';
				break;
			}
		}
	}
	return 0;
}