#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int match(string& a, string& b) {
	int count = 0;
	for (int i = 0; i < 8; i++)
		count += a[i] == b[i];
	return count;
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	int n;
	cin >> n;
	string s[n];
	for (int i = 0; i < n; i++)
		cin >> s[i];
	int state[n] = {};
	for (int i = n - 1; i >= 0; i--) {
		state[i] = 2;
		for (int j = 1; j <= 8; j++) {
			if (i + j >= n)
				break;
			if (match(s[i], s[i+j]) >= j) {
				if (state[i+j] == 2) {
					state[i] = 1;
					break;
				}
			}
		}
		cout << state[i];
	}
	cout << '\n';
	return 0;
}