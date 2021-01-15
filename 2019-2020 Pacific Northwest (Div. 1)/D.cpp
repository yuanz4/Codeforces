#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	int a, b;
	cin >> a >> b;
	int ans = 0;
	while (a > b) {
		if (a % 2 == 0)
			a /= 2;
		else
			a++;
		ans++;
	}
	cout << b - a + ans << '\n';
	return 0;
}