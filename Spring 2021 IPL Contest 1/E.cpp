#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 105;
const int INF = 2;

int gauss (vector<bitset<N>>& a, int m, int n, bitset<N>& ans) {
    vector<int> where (n, -1);
    for (int row = 0, col = 0; row < m && col < n; col++) {
        for (int i = row; i < m; i++) {
            if (a[i][col]) {
                swap(a[i], a[row]);
                break;
            }
        }
        if (!a[row][col])
            continue;
        where[col] = row;
        for (int i = 0; i < m; i++)
            if (i != row && a[i][col])
                a[i] ^= a[row];
        row++;
    }

    for (int i = 0; i < n; i++)
        if (where[i] != -1)
            ans[i] = a[where[i]][n] / a[where[i]][i];
    for (int i = 0; i < m; i++) {
        int sum = 0;
        for (int j = 0; j < n; j++)
            sum ^= ans[j] * a[i][j];
        if (sum != a[i][n])
            return 0;
    }
    for (int i = 0; i < n; i++)
        if (where[i] == -1)
            return INF;
    return 1;
}

void fail() {
	cout << "N" << '\n';
	exit(0);
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(0);
    int p, f;
    cin >> p >> f;
    vector<vector<int>> adj(p);
    int a, b;
    for (int i = 0; i < f; i++) {
    	cin >> a >> b;
    	a--, b--;
    	adj[a].push_back(b);
    	adj[b].push_back(a);
    }
    vector<bitset<N>> eq(p);
    for (int i = 0; i < p; i++) {
    	if (adj[i].empty())
    		fail();
    	if (adj[i].size() % 2 == 0) {
    		for (auto& j: adj[i])
    			eq[i][j] = 1;
    		eq[i][p] = 1;
    	} else {
    		eq[i][i] = 1;
    		for (auto& j: adj[i])
    			eq[i][j] = 1;
    	}
    }
    bitset<N> ans;
    int res = gauss(eq, p, p, ans);
    if (!res)
    	fail();
    cout << "Y" << '\n';
	return 0;
}