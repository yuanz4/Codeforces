#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int mod = 11092019;

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	string s;
	cin >> s;
	unordered_map<char, int> m;
	for (auto& i: s)
		m[i]++;
	ll ans = 1;
	for (auto& i: m)
		ans = (ans * (i.second + 1)) % mod;
	cout << ans << '\n'; 
	return 0;
}