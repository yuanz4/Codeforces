#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

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
		sort(a, a+n);
		int sum = 0;
		for (int i = 0; i < n; i++)
			sum += a[i];
		if (sum == 0)
			cout << "NO" << '\n';
		else {
			cout << "YES" << '\n';
			if (sum > 0)
				reverse(a, a+n);
			for (int i = 0; i < n; i++)
				cout << a[i] << ' ';
			cout << '\n';
		}
	}
	return 0;
}