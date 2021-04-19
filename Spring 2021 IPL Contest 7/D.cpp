#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAX = 1007;
const int mod = 1e9+7;

int n, k;
int d[MAX][MAX][2];

ll dfs(int p, int age, int dir) {
	if (p == 0 && dir == -1)
		return 1;
	if (p == n && dir == 1)
		return 1;
	if (d[p][age][dir] != 0)
		return d[p][age][dir];
	if (age == 1)
		d[p][age][dir] = dfs(p+dir, age, dir);
	else
		d[p][age][dir] = (dfs(p+dir, age, dir) + dfs(p, age-1, -dir)) % mod;
	return d[p][age][dir];
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	int test;
	cin >> test;
	while (test--) {
		cin >> n >> k;
		memset(d, 0, sizeof(d));
		cout << dfs(0, k, 1) << '\n';
	}
	return 0;
}