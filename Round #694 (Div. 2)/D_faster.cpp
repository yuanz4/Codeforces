#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX = 1e6+7;
int spf[MAX];

void sieve() {
	spf[1] = 1;
	for (int i = 2; i < MAX; i++) {
		if (i % 2 == 0)
			spf[i] = 2;
		else
			spf[i] = i;
	}
	for (int i = 3; i * i < MAX; i += 2) {
		if (spf[i] == i) {
			for (int j = i * i; j < MAX; j += i) {
				if (spf[j] == j)
					spf[j] = i;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	int test;
	cin >> test;
	sieve();
	while (test--) {
		int n;
		cin >> n;
		int a;
		unordered_map<int, int> cnt;
		for (int i = 0; i < n; i++) {
			cin >> a;
			unordered_set<int> s;
			int f = 1;
			while (a != 1) {
				int i = spf[a];
				if (!s.count(i)) {
					s.insert(i);
					f *= i;
				} else {
					s.erase(i);
					f /= i;
				}
				a /= i;
			}
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