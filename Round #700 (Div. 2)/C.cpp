#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int ask(int x) {
	cout << "? " << x << endl;
	int ans;
	cin >> ans;
	return ans;
}

void ans(int x) {
	cout << "! " << x << endl;
	exit(0);
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	int n;
	cin >> n;
	int low = 1, high = n;
	while (low <= high) {
		int m = (low + high) / 2;
		int mid = ask(m);
		int left = n + 1, right = n + 1;
		if (m != 1)
			left = ask(m - 1);
		if (m != n)
			right = ask(m + 1);
		if (left > mid && mid < right)
			ans(m);
		if (mid > left)
			high = m - 1;
		else
			low = m + 1;
	}
	return 0;
}