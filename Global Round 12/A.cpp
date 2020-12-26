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
		string a;
		cin >> a;
		sort(a.begin(), a.end());
		cout << a << '\n';
	}
	return 0;
}