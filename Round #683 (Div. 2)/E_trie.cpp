#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int mx = 2e5+7;
const int len = 30;

int child[len*mx][2];
int exist[len*mx];

int dfs(int node){
	if (exist[node])
		return 1;
	int ans1 = 0, ans2 = 0;
	if(child[node][0])
		ans1 = dfs(child[node][0]);
	if(child[node][1])
		ans2 = dfs(child[node][1]);
	return max(!!ans1 + ans2, ans1 + !!ans2);
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    int root = 0;
    int cnt = root;
	for(int i = 0; i < n; i++){
		int x;
		cin >> x;
		int node = root;
		for(int j = 29; j >= 0; j--){
			bool me = (x >> j) & 1;
			if(!child[node][me])
				child[node][me] = ++cnt;
			node = child[node][me];
		}
		exist[node] = 1;
	}
	cout << n - dfs(root) << '\n';
	return 0;
}