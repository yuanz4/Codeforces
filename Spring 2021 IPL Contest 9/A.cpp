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
		int a[n];
		for (int i = 0; i < n; i++)
			cin >> a[i];
		vector<int> ans;
		int cover = n;
		for (int i = n - 1; i >= 0; i--) {
			cover = min(cover, max(0, i + 1 - a[i]));
			ans.push_back(i >= cover);
		}
		reverse(ans.begin(), ans.end());
		for (auto& i: ans)
			cout << i << ' ';
		cout << '\n';
	}
	return 0;
}