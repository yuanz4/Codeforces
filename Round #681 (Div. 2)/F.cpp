#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int mod = 998244353;

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	int test;
	cin >> test;
	while (test--) {
		int n, k;
		cin >> n >> k;
		int a[n], b[k];
		unordered_map<int, int> m;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			m[a[i]] = i;
		}
		unordered_set<int> s;
		for (int i = 0; i < k; i++) {
			cin >> b[i];
			s.insert(b[i]);
		}
		ll ans = 0;
		for (int i = 0; i < k; i++) {
			s.erase(b[i]);
			int cur = 0;
			if (m[b[i]] && !s.count(a[m[b[i]]-1]))
				cur++;
			if (m[b[i]] < n-1 && !s.count(a[m[b[i]]+1]))
				cur++;
			if (cur == 0) {
				ans = 0;
				break;
			}
			if (i == 0)
				ans = cur;
			else
				ans = ans * cur % mod;
		}
		cout << ans << '\n';
	}
	return 0;
}