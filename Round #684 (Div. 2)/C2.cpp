#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

vector<vector<int>> ans;
vector<vector<int>> t;

void change(vector<int> v) {
	ans.push_back(v);
	for (int i = 0; i < 3; i++)
		t[v[i*2]][v[i*2+1]] = !t[v[i*2]][v[i*2+1]];
}

void cut(int i, int j) {
	if (!t[i][j])
		return;
	int n = t.size(), m = t[0].size();
	if (j == m-1) {
		if (i == 0)
			change({i, j, i, j-1, i+1, j-1});
		else
			change({i, j, i-1, j, i-1, j-1});
	} else
		change({i, j, i-1, j, i-1, j+1});
}

int fill(multiset<pair<int, pii>>& cell, int i, int j) {
	int zero = 0;
	for (int k = 0; k < 2; k++) {
		for (int l = 0; l < 2; l++) {
			int cur = t[i+k][j+l];
			if (cur == 0)
				zero++;
			cell.insert({cur, {i+k, j+l}});
		}
	}
	return zero;
}

int down(int zero, multiset<pair<int, pii>>& cell) {
	int skip;
	if (zero == 0 || zero == 2)
		skip = 3;
	else
		skip = 0;
	vector<int> cur;
	multiset<pair<int, pii>> temp = cell;
	int index = 0;
	for (auto c: temp) {
		if (index++ == skip)
			continue;
		cell.erase(c);
		c.first = !c.first;
		cell.insert(c);
		cur.push_back(c.second.first);
		cur.push_back(c.second.second);
	}
	ans.push_back(cur);
	zero += 3;
	if (zero > 4)
		zero -= 4;
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
		t = vector<vector<int>>(n, vector<int>(m));
		string s;
		for (int i = 0; i < n; i++) {
			cin >> s;
			for (int j = 0; j < m; j++)
				t[i][j] = s[j] - '0';
		}
		ans.clear();
		if (n % 2) {
			for (int j = 0; j < m-1; j++)
				cut(n-1, j);
		}
		if (n % 2 || m % 2)
			cut(n-1, m-1);
		if (m % 2) {
			for (int i = n-2; i >= 0; i--)
				cut(i, m-1);
		}
		for (int i = 0; i < n-1; i += 2) {
			for (int j = 0; j < m-1; j += 2) {
				multiset<pair<int, pii>> cell;
				int zero = fill(cell, i, j);
				while (zero != 4)
					zero = down(zero, cell);
				t[i][j] = t[i+1][j] = t[i][j+1] = t[i+1][j+1] = 0;
			}
		}
		cout << ans.size() << '\n';
		for (auto& i: ans) {
			for (auto& j: i)
				cout << j+1 << ' ';
			cout << '\n';
		}
	}
	return 0;
}