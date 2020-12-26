#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll mod = 1000000007;

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	int test;
	cin >> test;
	while (test--) {
		int n;
		cin >> n;
		int s = floor(sqrt(n));
		int ret = s - 1;
		ret += ceil((n-s)*1.0/s);
		cout << ret << '\n';
	}
	return 0;
}