#include <bits/stdc++.h>
using namespace std;

void pref(string& a, int p) {
	for (int i = 0; i < p; i++)
		a[i] = a[i] == '0' ? '1' : '0';
	reverse(a.begin(), a.begin()+p);
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	int test;
	cin >> test;
	while (test--) {
		int n;
		cin >> n;
		string a, b;
		cin >> a >> b;
		vector<int> ans;
		for (int i = n-1; i >= 0; i--) {
			if (a[i] == b[i])
				continue;
			if (a[0] == b[i]) {
				ans.push_back(1);
				pref(a, 1);
			}
			ans.push_back(i+1);
			pref(a, i+1);
		}
		cout << ans.size();
		for (auto& i: ans)
			cout << " " << i;
		cout << '\n';
	}
	return 0;
}