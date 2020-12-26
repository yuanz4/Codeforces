#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll mergeCount(vector<int>& a) {
	ll ans = 0, n = a.size();
	if (n > 1) {
		vector<int> b(a.begin(), a.begin()+n/2);
		vector<int> c(a.begin()+n/2, a.end());
		ans += mergeCount(b);
		ans += mergeCount(c);
		for (int i = 0, j = 0, k = 0; i < n; i++) {
			if (k == c.size())
				a[i] = b[j++];
			else if (j == b.size())
				a[i] = c[k++];
			else if (b[j] <= c[k])
				a[i] = b[j++];
			else {
				a[i] = c[k++];
				ans += n / 2 - j;
			}
		}
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
	cout << mergeCount(a) << '\n';
	return 0;
}