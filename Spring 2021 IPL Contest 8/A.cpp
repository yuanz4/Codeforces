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
		string a, b;
		cin >> a >> b;
		int count[2] = {};
		for (auto& i: a)
			count[i-'0']++;
		int flip = 0;
		bool ok = true;
		for (int i = n - 1; i >= 0; i--) {
			int cur = (a[i] - '0' + flip) % 2;
			if (cur + '0' == b[i]) {
				count[cur]--;
				continue;
			}
			if (count[0] == count[1]) {
				count[cur]--;
				swap(count[0], count[1]);
				flip++;
			} else {
				ok = false;
				break;
			}
		}
		if (ok)
			cout << "YES" << '\n';
		else
			cout << "NO" << '\n';
	}
	return 0;
}