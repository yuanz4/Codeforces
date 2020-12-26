#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll mod = 1000000007;

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	int n;
	cin >> n;
	ll cur, sum = 0;
	unordered_set<ll> pre;
	int ans = 0;
	for (int i = 0; i < n; i++) {
		cin >> cur;
		sum += cur;
		if (sum == 0 || pre.count(sum)) {
			ans++;
			sum = cur;
			pre.clear();
		}
		pre.insert(sum);
	}
	cout << ans << '\n';
	return 0;
}