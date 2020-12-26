#include <bits/stdc++.h>
using namespace std;

const int MAX = 5007;
int n;
int a[MAX];

int calc(int l, int r, int minus) {
	if (l >= r)
		return 0;
	int min_i = min_element(a+l, a+r) - a;
	int min_v = a[min_i];
	return min(r-l,
		calc(l, min_i, min_v) + calc(min_i+1, r, min_v) + min_v - minus);
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	cout << calc(0, n, 0) << '\n';
	return 0;
}