#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	int n;
	cin >> n;
	int a[3], b[3];
	for (int i = 0; i < 3; i++)
		cin >> a[i];
	for (int i = 0; i < 3; i++)
		cin >> b[i];
	cout << max({0, a[0]+b[1]-n, a[1]+b[2]-n, a[2]+b[0]-n}) << ' ';
	cout << min(a[0], b[1]) + min(a[1], b[2]) + min(a[2], b[0]) << '\n';
	return 0;
}