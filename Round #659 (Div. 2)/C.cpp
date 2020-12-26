#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n;
		string A, B;
		cin >> n >> A >> B;
		int ans = 0;
		map<char, multiset<char>> m;
		for (int i = 0; i < n; i++) {
			char a = A[i], b = B[i];
			if (a > b) {
				ans = -1;
				break;
			}
			if (a != b)				
				m[a].insert(b);
		}
		if (ans != -1) {
			while (!m.empty()) {
				auto it = m.begin();
				char a = it->first;
				char b = *it->second.begin();
				for (auto i = it->second.begin(); i != it->second.end();) {
					if (*i != b)
						break;
					it->second.erase(i++);
				}
				ans++;
				if (it->second.size())
					m[b].insert(it->second.begin(), it->second.end());
				m.erase(a);
			}
		}
		cout << ans << '\n';
	}
	return 0;
}