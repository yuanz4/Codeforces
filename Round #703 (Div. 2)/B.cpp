#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll seg(vector<int>& v) {
	sort(v.begin(), v.end());
	int l = v.size();
	if (l % 2 == 0)
		return v[l/2] - v[l/2-1] + 1;
	return 1;
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	int test;
	cin >> test;
	while (test--) {
		int n;
		cin >> n;
		vector<int> x(n), y(n);
		for (int i = 0; i < n; i++)
			cin >> x[i] >> y[i];
		cout << seg(x) * seg(y) << '\n';
	}
	return 0;
}