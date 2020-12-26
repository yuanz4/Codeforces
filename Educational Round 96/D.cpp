#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	int test;
	cin >> test;
	while (test--) {
		int n;
		cin >> n;
		string s;
		cin >> s;
		vector<int> v;
		for (int i = 0; i < n; i++) {
			int r = i;
			while (r != n-1 && s[r+1] == s[i]) {
				r++;
			}
			v.push_back(r-i+1);
			i = r;
		}
		int m = v.size();
		map<int, int> rich;
		for (int i = 0; i < m; i++) {
			if (v[i] > 1)
				rich[i] = v[i];
		}
		int ans = 0;
		int i = 0;
		while (i < m) {
			rich.erase(i);
			if (v[i] > 1) {
				ans++;
				i++;
			} else {
				if (!rich.empty()) {
					ans++;
					i++;
					auto it = rich.begin();
					it->second -= 1;
					v[it->first] -= 1;
					if (it->second == 1)
						rich.erase(it);
				} else {
					ans++;
					i += 2;
				}
			}
		}
		cout << ans << '\n';
	}
	return 0;
}