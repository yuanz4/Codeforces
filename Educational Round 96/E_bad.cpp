#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll bubbleCount(vector<int>& a) {
	bool flag = true;
	ll ans = 0;
	int n = a.size();
	while (flag) {
		flag = false;
		for (int i = 0; i < n-1; i++) {
			if (a[i] > a[i+1]) {
				flag = true;
				swap(a[i], a[i+1]);
				ans++;
			}
		}
	}
	return ans;
}

ll setCount(vector<int>& a) {
	int n = a.size();
	set<int> s;
	s.insert(a[0]);
	ll ans = 0;
	for (int i = 1; i < n; i++) {
		s.insert(a[i]);
		auto it = s.upper_bound(a[i]);
		ans += distance(it, s.end());
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
	cout << setCount(a) << '\n';
	return 0;
}