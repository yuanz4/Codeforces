#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (auto& i: a) {
		int count_smaller = 0;
		for (auto& j: a) {
			if (j < i)
				count_smaller++;
		}
		if (count_smaller == 1) {
			cout << i << '\n';
			return 0;
		}
	}
	assert(false);
	return 0;
}