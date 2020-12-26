#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll mod = 1e9+7;

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	int n;
	string s;
	cin >> n >> s;
	ll a = 0, ab = 0, abc = 0, num_string = 1;
	for (char c: s) {
		if (c == 'a')
			a = (a + num_string) % mod;
		else if (c == 'b')
			ab = (ab + a) % mod;
		else if (c == 'c')
			abc = (abc + ab) % mod;
		else {
			abc = (3 * abc + ab) % mod;
			ab = (3 * ab + a) % mod;
			a = (3 * a + num_string) % mod;
			num_string = (3 * num_string) % mod;
		}
	}
	cout << abc << '\n';
	return 0;
}