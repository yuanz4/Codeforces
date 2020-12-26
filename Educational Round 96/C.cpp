#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	int test;
	cin >> test;
	while (test--) {
		int n;
		cin >> n;
		int sum = n;
		vector<vector<int>> v;
		for (int i = n-1; i >= 1; i--) {
			int carry = 0;
			if ((sum + i) % 2 != 0)
				carry = 1;
			v.push_back({i, sum});
			sum = (sum + i) / 2 + carry;
		}
		cout << sum << '\n';
		for (auto& i: v) {
			cout << i[0] << " " << i[1] << '\n';
		}
	}
	return 0;
}