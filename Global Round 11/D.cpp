#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	int n;
	cin >> n;
	int c[n];
	for (int i = 0; i < n; i++) {
		cin >> c[i];
		c[i]--;
	}
	vector<vector<int>> ans;
	bool left = true;
	for (int i = 0; i < n; i++) {
		bool check = true;
		for (int i = 0; i < n; i++) {
			if (c[i] != i) {
				check = false;
				break;
			}
		}
		if (check)
			break;

		vector<int> cur;
		if (!left)
			reverse(c, c+n);
		int index = -1;
		for (int j = 0; j < n; j++) {
			if (i == c[j]) {
				index = j;
				break;
			}
		}
		for (int j = 0; j < i; j++)
			cur.push_back(1);
		cur.push_back(index+1-i);
		if (n-1-index)
			cur.push_back(n-1-index);
		reverse(c+i, c+index+1);
		reverse(c+index+1, c+n);
		reverse(c, c+n);
		if (!left) {
			reverse(c, c+n);
			reverse(cur.begin(), cur.end());
		}
		if (cur.size() != 1)
			ans.push_back(cur);
		left = !left;
	}
	cout << ans.size() << '\n';
	for (auto i: ans) {
		cout << i.size();
		for (int j: i)
			cout << " " << j;
		cout << '\n';
	}
	return 0;
}