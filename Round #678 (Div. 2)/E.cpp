#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	int n;
	cin >> n;
	int a[n];
	set<int> s;
	int mex = 1;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		s.insert(a[i]);
		while (s.count(mex)) {
			mex++;
		}
	}
	cout << mex << '\n';
	return 0;
}