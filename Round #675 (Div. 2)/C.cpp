#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll mod = 1000000007;

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	string s;
	cin >> s;
	ll sum = 0, time = 0, num = 0, prefix = 0;
	ll count = 1;
	for (char c: s) {
		ll cur = c - '0';
		sum = (sum*10+time*cur+prefix) % mod;
		time = (time+count++) % mod;
		num = (num*10+cur) % mod;
		prefix = (prefix+num) % mod;
	}
	cout << sum << '\n';
	return 0;
}