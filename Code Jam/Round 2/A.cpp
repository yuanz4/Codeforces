#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int query(int l, int r) {
	cout << "M " << l + 1 << " " << r + 1 << endl;
	int ans;
	cin >> ans;
	return ans - 1;
}

int sw(int i, int j) {
	if (i == j)
		return 0;
	if (i > j)
		swap(i, j);
	cout << "S " << i + 1 << " " << j + 1 << endl;
	int ans;
	cin >> ans;
	return ans - 1;
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	int test, n;
	cin >> test >> n;
	while (test--) {
		for (int i = 0; i < n; i++) {
			if (i == n - 1)
				continue;
			int s = query(i, n - 1);
			sw(s, i);
		}
		cout << "D" << endl;
		int ans;
		cin >> ans;
	}
	return 0;
}