#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	int n;
	cin >> n;
	int ans = 0;
	int cur = 0;
	int v;
	for (int i = 0; i < n; i++) {
		cin >> v;
		cur += v;
		ans = max(ans, cur);
	}
	cout << 100 + ans << '\n';
	return 0;
}