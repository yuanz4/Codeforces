#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	int test;
	cin >> test;
	while (test--) {
		string s;
		cin >> s;
		bool first = true;
		for (auto& i: s) {
			if (first) {
				if (i == 'a')
					i += 1;
				else
					i = 'a';
			} else {
				if (i == 'z')
					i -= 1;
				else
					i = 'z';
			}
			first = !first;
		}
		cout << s << '\n';
	}
	return 0;
}