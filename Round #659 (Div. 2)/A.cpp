#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int ch;

char next() {
	char c = 'a' + ch;
	ch++;
	if (ch > 25)
		ch = 1;
	return c;
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int a[n];
		for (int i = 0; i < n; i++)
			cin >> a[i];
		ch = 1;
		string s(60, 'a');
		cout << s << '\n';
		int prev = 0;
		for (int i = 0; i < n; i++) {
			char end = next();
			while (s[a[i]] == end) {
				end = next();
			}
			s[a[i]] = end;
			cout << s << '\n';
		}
	}
	return 0;
}