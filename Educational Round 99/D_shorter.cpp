#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	int test;
	cin >> test;
	while (test--) {
		int n, x;
		cin >> n >> x;
		vector<int> a(n);
		for (int i = 0; i < n; i++)
			cin >> a[i];
		int step = 0;
		while (!is_sorted(a.begin(), a.end())) {
			int index = -1;
			for (int i = 0; i < n; i++) {
				if (a[i] > x) {
					index = i;
					break;
				}
			}
			if (index < 0)
				break;
			swap(a[index], x);
			step++;
		}
		if (!is_sorted(a.begin(), a.end()))
			step = -1;
		cout << step << '\n';
	}
	return 0;
}

