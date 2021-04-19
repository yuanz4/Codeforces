#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int d[10005][10005];

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	int test;
	cin >> test;
	while (test--) {
		int n, k;
		cin >> n >> k;
		memset(d, 0, sizeof(d));
		d[0][0] = k - 1;
		for (int i = 0; i < n - 1; i++) {
			for (int j = 0; j <= i; j++) {
				d[i+1][j] += (d[i][j] + 1) / 2;
				d[i+1][j+1] += d[i][j] / 2;
			}
		}
		int j = 0;
		for (int i = 0; i < n - 1; i++)
			j += d[i][j] % 2;
		cout << j << '\n'; 
	}
	return 0;
}