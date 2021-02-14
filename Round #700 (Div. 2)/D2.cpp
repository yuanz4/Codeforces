#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; i++)
		cin >> a[i];
	vector<int> b;
	for (int i = 0; i < n; i++) {
		int r = i;
		while (r + 1 < n && a[i] == a[r + 1])
			r++;
		int len = r - i + 1;
		b.push_back(a[i]);
		i = r;
	}
	int m = b.size();
	int last = 0;
	int ans = 0;
	unordered_set<int> alter;
	for (int i = 0; i < m; i++) {
		if (alter.count(b[i]))
			alter.clear();
		else
			ans++;
		alter.insert(last);
		last = b[i];
	}
	cout << ans << '\n';
	return 0;
}