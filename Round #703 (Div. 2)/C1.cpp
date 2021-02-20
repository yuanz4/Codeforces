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
	int low = 1, high = n;
	while (low < high) {
		int mid = (low + high) / 2;
		int smax = ask(low, high);
		if (smax <= mid) {
			int lsmax = ask(low, mid);
			if (lsmax == smax)
				high = mid;
			else
				low = mid + 1;
		} else {
			int rsmax = ask(mid + 1, high);
			if (rsmax == smax)
				low = mid + 1;
			else
				high = mid;
		}
	}
	cout << "! " << low << '\n';
	return 0;
}