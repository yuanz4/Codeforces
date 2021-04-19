#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	int test;
	cin >> test;
	for (int t = 1; t <= test; t++) {
		cout << "Case #" << t << ": ";
		int n;
		cin >> n;
		int a[n];
		for (int i = 0; i < n; i++)
			cin >> a[i];
		int count = 0;
		for (int i = 0; i < n - 1; i++) {
			auto j = min_element(a + i, a + n);
			count += j - (a + i) + 1;
			reverse(a + i, j + 1);
		}
		cout << count << '\n';
	}
	return 0;
}