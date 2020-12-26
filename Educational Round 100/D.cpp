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
		int b[n];
		for (int i = 0; i < n; i++)
			cin >> b[i];
		int gap = 0;
		int low = 0;
		for (int i = n-1; i >= 0; i--) {
			int cur;
			if (i == n-1)
				cur = 2*n - b[i];
			else
				cur = b[i+1] - b[i] - 1;
			gap += cur;
			int right = n - 1 - i;
			low = max(low, max(gap - right, 0));
		}
		gap = 0;
		int high = 0;
		for (int i = 0; i < n; i++) {
			int cur;
			if (i == 0)
				cur = b[i] - 1;
			else
				cur = b[i] - b[i-1] - 1;
			gap += cur;
			int left = i;
			high = max(high, max(gap - left, 0));
		}
		cout << (n - high) - low + 1 << '\n';
	}
	return 0;
}