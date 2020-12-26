#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void visualize(int d[], int n, int k, int l) {
	for (int i = 0; i <= n; i++) {
		string cur;
		for (int j = 0; j < k; j++) {
			if (d[i] + j <= l)
				cur += '.';
			else
				cur += ' ';
		}
		for (int j = k; j > 0; j--) {
			if (d[i] + j <= l)
				cur += '.';
			else
				cur += ' ';
		}
		cout << cur << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	int test;
	cin >> test;
	while (test--) {
		int n, k, l;
		cin >> n >> k >> l;
		int d[n+1] = {};
		for (int i = 1; i <= n; i++)
			cin >> d[i];
		// visualize(d, n, k, l);
		int tide = k;
		bool down = true;
		for (int i = 1; i <= n; i++) {
			if (d[i]+k <= l) {
				tide = k;
				down = true;
			} else {
				tide += down ? -1 : 1;
				if (down && tide >= l-d[i] && l-d[i] >= 0)
					tide = l-d[i];
				if (l < d[i] || d[i]+tide > l) {
					cout << "No" << '\n';
					goto next;
				}
				if (!tide)
					down = false;
			}
		}
		cout << "YES" << '\n';
		next:;
	}
	return 0;
}