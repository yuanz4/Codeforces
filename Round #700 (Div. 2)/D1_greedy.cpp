#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	int n;
	cin >> n;
	int a[n+1];
	a[0] = 0;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	int nxt[n], pos[n+1];
	for (int i = 0; i <= n; i++)
		pos[i] = n + 1;
	for (int i = n; i >= 0; i--) {
		nxt[i] = pos[a[i]];
		pos[a[i]] = i;
	}
	int x = 0, y = 0;
	int ans = 0;
	for (int z = 1; z <= n; z++) {
		if (a[x] == a[z]) {
			ans += a[y] != a[z];
			y = z;
		} else if (a[y] == a[z]) {
			ans += a[x] != a[z];
			x = z;
		} else if (nxt[x] < nxt[y]) {
			ans++;
			x = z;
		} else {
			ans++;
			y = z;
		}
	}
	cout << ans << '\n';
	return 0;
}