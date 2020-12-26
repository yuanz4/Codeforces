#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int mx = 2e5+7;
int a[mx];

int dfs(int l, int r, int bit) {
	if (l > r)
		return 0;
	if (l == r)
		return 1;
	int left = l, right = r;
	int bound = l;
	while (left <= right) {
		int mid = (left + right) / 2;
		if ((a[mid] >> bit) & 1) {
			bound = mid;
			right = mid - 1;
		} else
			left = mid + 1;
	}
	int ans1 = dfs(l, bound-1, bit-1);
	int ans2 = dfs(bound, r, bit-1);
	return max(!!ans1+ans2, ans1+!!ans2);
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	sort(a, a+n);
	cout << n - dfs(0, n-1, 30) << '\n';
	return 0;
}