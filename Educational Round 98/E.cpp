#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct seg {
	int l, r;
};

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	int n, m, k;
	cin >> n >> m >> k;
	seg a[m];
	for (int i = 0; i < m; i++) {
		cin >> a[i].l >> a[i].r;
		a[i].l--;
		a[i].r--;
	}
	sort(a, a+m, [](const seg& i, const seg& j) {
		return i.l + i.r < j.l + j.r;
	});
	int suffix[m+1] = {};
	for (int i = 0; i < n-k+1; i++) {
		int cur = 0;
		for (int j = m-1; j >= 0; j--) {
			cur += max(min(a[j].r, i+k-1)+1-max(a[j].l, i), 0);
			suffix[j] = max(suffix[j], cur);
		}
	}
	int ans = suffix[0];
	for (int i = 0; i < n-k+1; i++) {
		int cur = 0;
		for (int j = 0; j < m; j++) {
			cur += max(min(a[j].r, i+k-1)+1-max(a[j].l, i), 0);
			ans = max(ans, cur + suffix[j+1]);
		}
	}
	cout << ans << '\n';
	return 0;
}