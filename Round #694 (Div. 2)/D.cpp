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
		int a;
		unordered_map<int, int> cnt;
		for (int i = 0; i < n; i++) {
			cin >> a;
			unordered_set<int> s;
			int f = 1;
			for (int i = 2; i * i <= a; i++) {
				while (a % i == 0) {
					if (!s.count(i)) {
						s.insert(i);
						f *= i;
					} else {
						s.erase(i);
						f /= i;
					}
					a /= i;
				}
			}
			if (a > 1)
				f *= a;
			cnt[f]++;
		}
		int zero = 0, one = 0;
		for (auto& i: cnt) {
			if (i.first == 1 || i.second % 2 == 0)
				one += i.second;
			zero = max(zero, i.second);
		}
		one = max(zero, one);
		int q;
		cin >> q;
		ll w;
		for (int i = 0; i < q; i++) {
			cin >> w;
			if (w == 0)
				cout << zero << ' ';
			else
				cout << one << ' ';
		}
		cout << '\n';
	}
	return 0;
}