#include <bits/stdc++.h>
using namespace std;

#define printv(v) for (auto& i: v) cout << i << " "; cout << endl;
typedef long long ll;
const ll mod = 998244353;
vector<ll> fact, invf;

ll powmod(ll a, ll b) {
	ll res = 1;
	a %= mod;
	for (; b; b >>= 1) {
		if (b & 1)
			res = res * a % mod;
		a = a * a % mod;
	}
	return res;
}

void build(int n) {
	fact = vector<ll>(n+1, 1);
	invf = vector<ll>(n+1, 1);
	for (int i = 2; i <= n; i++)
		fact[i] = fact[i-1] * i % mod;
	invf[n] = powmod(fact[n], mod-2);
	for (int i = n-1; i >= 2; i--)
		invf[i] = invf[i+1] * (i+1) % mod;
}

ll nChoosek(int n, int k) {
    if (n < k)
    	return 0;
    return fact[n] * invf[k] % mod * invf[n-k] % mod;
}

int main() {
	int n, k;
	scanf("%d %d", &n, &k);
	build(n);
	vector<vector<int>> l(n, vector<int>(2));
	for (int i = 0; i < n; i++)
		scanf("%d %d", &l[i][0], &l[i][1]);
	sort(l.begin(), l.end());
	priority_queue<int, vector<int>, greater<int>> pq;
	ll ret = 0;
	for (int i = 0; i < n; i++) {
		int start = l[i][0];
		int end = l[i][1];
		while (!pq.empty() && pq.top() < start)
			pq.pop();
		ret += nChoosek(pq.size(), k-1) % mod;
		pq.push(end);
	}
	printf("%lld\n", ret % mod);
	return 0;
}