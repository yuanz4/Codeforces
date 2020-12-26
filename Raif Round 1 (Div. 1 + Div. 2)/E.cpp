#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ll, ii> lii;

ll val(ll l, ll p) {
	ll c1 = l / p;
	ll c2 = c1 + 1;
	ll cnt2 = l % p;
	ll cnt1 = p - cnt2;
	return c1*c1*cnt1 + c2*c2*cnt2;
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	int n, k;
	cin >> n >> k;
	priority_queue<lii> pq;
	ll ans = 0;
	for (int i = 0; i < n; i++) {
		ll a;
		cin >> a;
		ans += val(a, 1);
		pq.push({val(a,1)-val(a,2), {a, 2}});
	}
	for (int i = 0; i < k-n; i++) {
		lii top = pq.top();
		pq.pop();
		ans -= top.first;
		ll l = top.second.first;
		ll p = top.second.second;
		pq.push({val(l,p)-val(l,p+1), {l, p+1}});
	}
	cout << ans << '\n';
	return 0;
}