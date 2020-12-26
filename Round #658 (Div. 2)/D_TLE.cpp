#include <bits/stdc++.h>
using namespace std;

bool found;

void dfs(vector<int>& v, int i, vector<vector<int>>& p,
	vector<int>& biggest, int index) {
	if (found)
		return;
	int n = v.size() / 2;
	if (p[0].size() > n || p[1].size() > n)
		return;
	if (i == 2*n) {
		found = true;
		return;
	}
	if (p[index].empty() || v[i] < p[index].back()) {
		p[index].push_back(v[i]);
		int ori = biggest[index];
		biggest[index] = max(ori, v[i]);
		dfs(v, i+1, p, biggest, index);
		biggest[index] = ori;
		p[index].pop_back();
	} else {
		p[index].push_back(v[i]);
		int ori = biggest[index];
		biggest[index] = max(ori, v[i]);
		dfs(v, i+1, p, biggest, index);
		biggest[index] = ori;
		p[index].pop_back();
		if (v[i] > biggest[index]) {
			p[1-index].push_back(v[i]);
			int ori = biggest[1-index];
			biggest[1-index] = max(ori, v[i]);
			dfs(v, i+1, p, biggest, 1-index);
			biggest[1-index] = ori;
			p[1-index].pop_back();
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	int test;
	cin >> test;
	while (test--) {
		int n;
		cin >> n;
		vector<int> v(2*n);
		for (int i = 0; i < 2*n; i++)
			cin >> v[i];
		found = false;
		vector<vector<int>> p(2, vector<int>());
		vector<int> biggest{-1, -1};
		dfs(v, 0, p, biggest, 0);
		if (found)
			cout << "YES" << '\n';
		else
			cout << "NO" << '\n';
	}
	return 0;
}