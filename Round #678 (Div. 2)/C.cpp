#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll mod = 1e9+7;

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	int n, x, pos;
	cin >> n >> x >> pos;
	int bigger = 0, smaller = 0;
	int left = 0, right = n;
	while (left < right) {
		int middle = (left + right) / 2;
		if (middle <= pos) {
			left = middle + 1;
			if (middle < pos)
				smaller++;
		} else {
			right = middle;
			bigger++;
		}
	}
	ll ans = 1;
	for (int i = n-x; i > n-x-bigger; i--)
		ans = ans * i % mod;
	for (int i = x-1; i > x-1-smaller; i--)
		ans = ans * i % mod;
	for (int i = 1; i <= n-bigger-smaller-1; i++)
		ans = ans * i % mod;
	cout << ans << '\n';
	return 0;
}