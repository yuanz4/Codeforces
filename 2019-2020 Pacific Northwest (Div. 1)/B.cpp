#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	int n, k;
	cin >> n >> k;
	int a[n];
	int last[k];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		a[i]--;
		last[a[i]] = i;
	}
	deque<int> d;
	unordered_set<int> in;
	for (int i = 0; i < n; i++) {
		if (in.count(a[i]))
			continue;
		if (d.empty() || d.back() < a[i]) {
			d.push_back(a[i]);
			in.insert(a[i]);
		} else {
			while (d.size() && a[i] < d.back() && i < last[d.back()]) {
				in.erase(d.back());
				d.pop_back();
			}
			d.push_back(a[i]);
			in.insert(a[i]);
		}
	}
	while (d.size()) {
		cout << d.front() + 1 << ' ';
		d.pop_front();
	}
	cout << '\n';
	return 0;
}