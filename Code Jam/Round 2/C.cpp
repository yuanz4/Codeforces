#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll mod = 1e9 + 7;
const int MAX = 15;

int n;
int a[MAX];
ll ans;

void dfs(vector<int>& order, int index, unordered_set<int>& s) {
	if (index) {
		int count = 0;
		int top = 0;
		for (int i = index - 1; i >= 0; i--) {
			if (top < order[i])
				count++;
			top = max(top, order[i]);
		}
		if (count != a[index-1])
			return;
	}
	if (index == n) {
		ans = (ans + 1) % mod;
		return;
	}
	int l = 1, r = n;
	if (index != 0) {
		if (a[index] > a[index-1])
			r = order[index-1] - 1;
		else
			l = order[index-1] + 1;
	}
	for (int i = l; i <= r; i++) {
		if (!s.count(i)) {
			s.insert(i);
			order.push_back(i);
			dfs(order, index + 1, s);
			order.pop_back();
			s.erase(i);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	int test;
	cin >> test;
	for (int t = 1; t <= test; t++) {
		cout << "Case #" << t << ": ";
		cin >> n;
		for (int i = 0; i < n; i++)
			cin >> a[i];
		vector<int> order;
		ans = 0;
		unordered_set<int> s;
		dfs(order, 0, s);
		cout << ans << '\n';
	}
	return 0;
}