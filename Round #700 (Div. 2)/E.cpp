#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<vector<int>> edges;

void add(int a, int b, int c) {
	edges.push_back({a, b, c});
}

int solve(int L, int R) {
	if (L > 1) {
		int n = solve(1, R - L + 1);
		add(n, n + 1, L - 1);
		return n + 1;
	}
	if ((R & -R) == R) {
		int k = __builtin_ctz(R);
		for (int i = 2; i <= k + 2; i++) {
			add(1, i, 1);
			for (int j = 2; j < i; j++)
				add(j, i, 1 << (j - 2));
		}
		return k + 2;
	}
	int k = log2(R - 1);
	solve(1, 1 << k);
	add(1, k + 3, 1);
	for (int i = 0; i <= k; i++) {
		if (((R - 1) >> i) & 1) {
			int right = ((R - 1) >> i << i) ^ (R - 1);
			add(i + 2, k + 3, 1 + right);
		}
	}
	return k + 3;
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	int L, R;
	cin >> L >> R;
	int n = solve(L, R);
	cout << "YES" << '\n';
	cout << n << " " << edges.size() << '\n';
	for (auto& i: edges)
		cout << i[0] << " " << i[1] << " " << i[2] << '\n';
	return 0;
}