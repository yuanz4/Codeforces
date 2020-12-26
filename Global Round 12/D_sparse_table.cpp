#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

bool check(vector<int>& a) {
	int n = a.size();
	int b[n] = {};
	for (int i = 0; i < n; i++) {
		if (b[a[i]])
			return false;
		b[a[i]]++;
	}
	return true;
}

struct SparseTable {
	int n;
	vector<vector<int>> mat;

	SparseTable(vector<int>& v) {
		n = v.size();
		int max_log = 32 - __builtin_clz(n);
		mat.resize(max_log);
		mat[0] = v;
		for (int j = 1; j < max_log; j++) {
			mat[j].resize(n - (1 << j) + 1);
			for (int i = 0; i <= n - (1 << j); i++)
				mat[j][i] = min(mat[j-1][i], mat[j-1][i+(1<<(j-1))]);
		}
	}

	int get(int from, int to) {
		int lg = 32 - __builtin_clz(to - from + 1) - 1;
		return min(mat[lg][from], mat[lg][to-(1<<lg)+1]);
	}
};

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	int test;
	cin >> test;
	while (test--) {
		int n;
		cin >> n;
		vector<int> a(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			a[i]--;
		}
		string ans(n, '0');
		if (check(a))
			ans[0] = '1';
		SparseTable st(a);
		auto test = [&](int x, int y, int z) {
			if (st.get(x, y) == z)
				ans[n-1-z] = '1';
		};
		test(0, n-1, 0);
		int num = 0;
		int l = 0, r = n-1;
		while (l < r) {
			if (a[l] == num)
				test(++l, r, ++num);
			else if (a[r] == num)
				test(l, --r, ++num);
			else
				break;
		}
		cout << ans << '\n';
	}
	return 0;
}