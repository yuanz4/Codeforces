#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	int n, k;
	cin >> n >> k;
	int c[n];
	for (int i = 0; i < n; i++)
		cin >> c[i];
	sort(c, c+n, greater<int>());
	priority_queue<ll> pq;
	for (int i = 0; i < k + 1; i++)
		pq.push(0);
	ll ans = 0;
	for (int i = 0; i < n; i++) {
		ll x = pq.top();
		pq.pop();
		ans += x;
		x += c[i];
		pq.push(x);
	}
	cout << ans << '\n';
	return 0;
}