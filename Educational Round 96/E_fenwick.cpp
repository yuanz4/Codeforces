#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 2e5+7;
int t[MAXN];

int ask(int x) {
    int ans = 0;
    for (; x; x -= x&-x)
    	ans += t[x];
    return ans;
}

void add(int x, int y) {
    for(; x < MAXN; x += x&-x)
        t[x] += y;
}

ll fenwickCount(vector<int>& a) {
	ll ans = 0, n = a.size();
	for (int i = 0; i < n; i++) {
		ans += i - ask(a[i]+1);
		add(a[i]+1, 1);
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	int n;
	cin >> n;
	string s;
	cin >> s;
	map<char, vector<int>> m;
	for (int i = 0; i < n; i++)
		m[s[i]].push_back(n-i-1);
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		a[i] = m[s[i]].back();
		m[s[i]].pop_back();
	}
	cout << fenwickCount(a) << '\n';
	return 0;
}