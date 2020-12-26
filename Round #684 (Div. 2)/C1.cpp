#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

vector<vector<pii>> ans;
vector<string> t;

int down(int zero, multiset<pair<int, pii>>& cell) {
	int skip;
	if (zero == 0 || zero == 2)
		skip = 3;
	else
		skip = 0;
	vector<pii> cur;
	multiset<pair<int, pii>> temp = cell;
	int index = 0;
	for (auto c: temp) {
		if (index++ == skip)
			continue;
		cell.erase(c);
		c.first = !c.first;
		cell.insert(c);
		cur.push_back({c.second.first, c.second.second});
	}
	ans.push_back(cur);
	zero += 3;
	if (zero > 4)
		zero -= 4;
	return zero;
}

int fill(multiset<pair<int, pii>>& cell, int i, int j) {
	cell.clear();
	int zero = 0;
	for (int k = 0; k < 2; k++) {
		for (int l = 0; l < 2; l++) {
			int cur = t[i+k][j+l] - '0';
			if (cur == 0)
				zero++;
			cell.insert({cur, {i+k, j+l}});
		}
	}
	return zero;
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	int test;
	cin >> test;
	while (test--) {
		int n, m;
		cin >> n >> m;
		t = vector<string>(n);
		for (int i = 0; i < n; i++)
			cin >> t[i];
		ans.clear();
		for (int i = 0; i < n-1; i++) {
			for (int j = 0; j < m-1; j++) {
				multiset<pair<int, pii>> cell;
				int zero = fill(cell, i, j);
				while (zero != 4)
					zero = down(zero, cell);
				t[i][j] = t[i+1][j] = t[i][j+1] = t[i+1][j+1] = '0';
			}
		}
		cout << ans.size() << endl;
		for (int i = 0; i < ans.size(); i++) {
			for (int j = 0; j < 3; j++)
				cout << ans[i][j].first+1 << " " << ans[i][j].second+1 << " ";
			cout << '\n';
		}
	}
	return 0;
}