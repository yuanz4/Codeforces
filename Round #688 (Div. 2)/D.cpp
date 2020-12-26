#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	int test;
	cin >> test;
	while (test--) {
		ll k;
		cin >> k;
		if (k % 2) {
			cout << -1 << '\n';
			continue;
		}
		int bit = 62;
		vector<int> ans;
		while (k) {
			ll cur = (1ll << (bit + 1)) - 2;
			if (k >= cur) {
				k -= cur;
				ans.push_back(1);
				for (int i = 0; i < bit-1; i++)
					ans.push_back(0);
			} else
				bit--;
		}
		cout << ans.size() << '\n';
		for (auto& i: ans)
			cout << i << ' ';
		cout << '\n';
	}
	return 0;
}