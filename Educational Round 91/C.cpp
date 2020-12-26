#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	int test;
	cin >> test;
	while (test--) {
		ll n, x;
		cin >> n >> x;
		ll a[n];
		for (int i = 0; i < n; i++)
			cin >> a[i];
		sort(a, a+n);
		int team = 0;
		int count = 0;
		for (int i = n-1; i >= 0; i--) {
			count++;
			if (count * a[i] >= x) {
				team++;
				count = 0;
			}
		}
		cout << team << '\n';
	}
	return 0;
}