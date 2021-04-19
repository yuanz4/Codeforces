#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void good(int a, int b, int c, int d) {
	cout << "YES" << '\n';
	cout << a << " " << b << " " << c << " " << d << '\n';
	exit(0);
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	int n;
	cin >> n;
	pair<int, int> a[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i].first;
		a[i].second = i + 1;
	}
	sort(a, a+n);
	unordered_map<int, pair<int, int>> m;
	if (n <= 3500) {
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				int u = a[i].second;
				int v = a[j].second;
				int sum = a[i].first + a[j].first;
				if (m.count(sum)) {
					int x = m[sum].first;
					int y = m[sum].second;
					if (x != u && x != v && y != u && y != v)
						good(x, y, u, v);
				} else
					m[sum] = {u, v};
			}
		}
	} else {
		for (int i = 0; i < n - 1; i++) {
			int diff = a[i+1].first - a[i].first;
			int u = a[i].second;
			int v = a[i+1].second;
			if (m.count(diff)) {
				if (u != m[diff].second)
					good(m[diff].first, v, m[diff].second, u);
			} else
				m[diff] = {u, v};
		}
	}
	cout << "NO" << '\n';
	return 0;
}