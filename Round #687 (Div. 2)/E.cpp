#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	int n, k;
	cin >> n >> k;
	ll c[n];
	for (int i = 0; i < n; i++)
		cin >> c[i];
	ll ans = 0;
	sort(c, c+n, greater<ll>());
	ll sum = 0;
	int end = n;
	for (int i = 0; i < n; i++) {
		sum += c[i];
		if (sum < 0) {
			end = i;
			break;
		}
	}
	for (int i = n-1; i >= end; i--)
		ans += c[i] * ((n-1-i) / (k+1));
	int high = (n-end) / (k+1) + !!((n-end) % (k+1));
	for (int i = 0; i < end; i++)
		ans += (end - i + high - 1) * c[i];
	cout << ans << '\n';
	return 0;
}