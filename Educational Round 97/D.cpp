#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	int test;
	cin >> test;
	while (test--) {
		int n;
		cin >> n;
		int a[n];
		for (int i = 0; i < n; i++)
			cin >> a[i];
		int pre = 1, height = 0, temp = 0;
		bool start = true;
		for (int i = 1; i < n; i++) {
			int r = i;
			while (r < n-1 && a[r+1] > a[r])
				r++;
			if (start) {
				height++;
				start = false;
			}
			pre--;
			temp += r-i+1;
			if (pre == 0) {
				start = true;
				pre = temp;
				temp = 0;
			}
			i = r;
		}
		cout << height << '\n';
	}
	return 0;
}