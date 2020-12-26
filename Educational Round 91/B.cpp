#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	int test;
	cin >> test;
	while (test--) {
		string s;
		cin >> s;
		map<char, int> m;
		for (auto& i: s) {
			m[i]++;
		}
		map<int, char> mi;
		for (auto& i: m) {
			mi[i.second] = i.first;
		}
		char most = mi.rbegin()->second;
		map<char, char> lose{{'R', 'P'}, {'S', 'R'}, {'P', 'S'}};
		string ans(s.size(), lose[most]);
		cout << ans << '\n';
	}
	return 0;
}