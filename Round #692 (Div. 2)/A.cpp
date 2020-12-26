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
		string s;
		cin >> s;
		int count = 0;
		for (int i = n-1; i >= 0; i--) {
			if (s[i] == ')')
				count++;
			else
				break;
		}
		if (count > n - count)
			cout << "Yes" << '\n';
		else
			cout << "No" << '\n';
	}
	return 0;
}