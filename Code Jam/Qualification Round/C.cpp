#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	int test;
	cin >> test;
	for (int t = 1; t <= test; t++) {
		cout << "Case #" << t << ": ";
		int n, c;
		cin >> n >> c;
		if (c < n - 1 || c >= n * (n + 1) / 2)
			cout << "IMPOSSIBLE" << '\n';
		else {
			c -= n - 1;
			vector<int> ans(n);
			bool r = true;
			set<int> pos;
			for (int i = 0; i < n; i++)
				pos.insert(i);
			for (int i = 1; i <= n; i++) {
				auto cur = pos.begin();
				if (i != n) {
					if (c >= n - i) {
						c -= n - i;
						if (r)
							cur = prev(pos.end());
						r = !r;
					} else {
						if (!r)
							cur = prev(pos.end());
					}
				}
				ans[*cur] = i;
				pos.erase(cur);
			}
			for (auto& i: ans)
				cout << i << " ";
			cout << endl;
		}
	}
	return 0;
}