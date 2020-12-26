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
		int a[n];
		for (int i = 0; i < n; i++)
			cin >> a[i];
		int index = 0;
		int step = 0;
		while (true) {
			int start = -1;
			int end = -1;
			for (int i = index; i < n-1; i++) {
				if (a[i] > x && start == -1)
					start = i;
				if (a[i] > a[i+1]) {
					end = i;
					break;
				}
			}
			if (end == -1)
				break;
			if (end != -1 && start == -1) {
				step = -1;
				break;
			}
			for (int i = start; i <= end; i++) {
				if (a[i] > x) {
					swap(a[i], x);
					step++;
				}
			}
			if (a[end] > a[end+1]) {
				step = -1;
				break;
			} else
				index = end + 1;
		}
		cout << step << '\n';
	}
	return 0;
}