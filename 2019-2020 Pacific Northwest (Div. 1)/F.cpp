#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX = 55;
const ll INF = 2e18;

ll c[MAX][MAX], f[MAX], g[MAX][MAX];

ll add(ll a, ll b) {
	ll c = a + b;
	if (c >= INF)
		return INF;
	return c;
}

ll mul(ll a, ll b) {
	if (b > 0 && a > INF / b)
		return INF;
	return a * b;
}

ll g3(ll n, ll m, ll x) {
	return mul(c[x][m], g[n-m][x-m]);
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(0);
    f[0] = 1;
    for (int i = 1; i < MAX; i++)
    	f[i] = mul(f[i-1], i);
    for (int i = 0; i < MAX; i++) {
    	c[i][0] = c[i][i] = 1;
    	for (int j = 1; j < i; j++)
    		c[i][j] = add(c[i-1][j-1], c[i-1][j]);
    }
    for (int i = 0; i < MAX; i++) {
    	g[i][0] = f[i];
    	g[i][1] = mul(i - 1, g[i-1][0]);
    	for (int j = 2; j <= i; j++)
    		g[i][j] = add(mul(j-1, g[i-1][j-2]), mul(i-j, g[i-1][j-1]));
    }
    ll n, p, k;
    cin >> n >> p >> k;
    k--;
    if (g3(n, p, n) <= k) {
    	cout << -1 << '\n';
    	return 0;
    }
    bool used[n] = {};
    ll x = n;
    for (int pos = 0; pos < n; pos++) {
    	x -= !used[pos];
    	for (int dig = 0; dig < n; dig++) {
    		if (used[dig])
    			continue;
    		if (p == 0 && dig == pos)
    			continue;
    		ll cnt = g3(n-1-pos, p-(dig==pos), x-(dig>pos));
    		if (k >= cnt)
    			k -= cnt;
    		else {
    			cout << dig + 1 << ' ';
    			used[dig] = true;
    			if (dig == pos)
    				p--;
    			if (dig > pos)
    				x--;
    			break;
    		}
    	}
    }
    cout << '\n';
	return 0;
}