#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX = 55;
ll c[MAX][MAX];
int n;
vector<ll> w;

ll ways(ll remain, int k, int index) {
	if (index == n || k == 0)
		return k == 0;
	if (w[index] > remain)
		return ways(remain, k, index + 1);
	ll ans = 0;
	ans += c[n-index-1][k];
	ans += ways(remain - w[index], k - 1, index + 1);
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	int k;
	cin >> n >> k;
	w.resize(n);
	for (int i = 0; i < n; i++)
		cin >> w[i];
	sort(w.begin(), w.end(), greater<ll>());
	ll a, b;
	cin >> a >> b;
	for (int i = 0; i < MAX; i++) {
    	c[i][0] = c[i][i] = 1;
    	for (int j = 1; j < i; j++)
    		c[i][j] = c[i-1][j-1] + c[i-1][j];
    }
    ll high = ways(b, k, 0);
    ll low = ways(a-1, k, 0);
    cout << high - low << '\n';
	return 0;
}