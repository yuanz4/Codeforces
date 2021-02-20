#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int ask(int l, int r) {
	if (l == r)
		return -1;
	cout << "? " << l << " " << r << endl;
	int ans;
	cin >> ans;
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	int n;
	cin >> n;
	int smax = ask(1, n);
	int ans;
	if (smax == ask(1, smax)) {
		int low = 1, high = smax - 1;
		while (low <= high) {
			int mid = (low + high) / 2;
			if (ask(mid, smax) == smax) {
				ans = mid;
				low = mid + 1;
			} else
				high = mid - 1;
		}
	} else {
		int low = smax + 1, high = n;
		while (low <= high) {
			int mid = (low + high) / 2;
			if (ask(smax, mid) == smax) {
				ans = mid;
				high = mid - 1;
			} else
				low = mid + 1;
		}
	}
	cout << "! " << ans << '\n';
	return 0;
}