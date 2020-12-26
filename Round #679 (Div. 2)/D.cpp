#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	int n;
	cin >> n;
	int a[2*n];
	char c;
	for (int i = 0; i < 2*n; i++) {
		cin >> c;
		if (c == '+')
			a[i] = 0;
		else
			cin >> a[i];
	}
	vector<int> ret;
	stack<int> s;
	for (int i = 2*n-1; i >= 0; i--) {
		if (a[i] != 0) {
			if (s.empty() || a[i] < s.top()) {
				s.push(a[i]);
			} else {
				cout << "NO" << '\n';
				return 0;
			}
		} else {
			if (s.empty()) {
				cout << "NO" << '\n';
				return 0;
			}
			int it = s.top();
			ret.push_back(it);
			s.pop();
		}
	}
	cout << "YES" << '\n';
	for (int i = n-1; i >= 0; i--)
		cout << ret[i] << ' ';
	cout << '\n';
	return 0;
}