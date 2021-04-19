#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	int n, d;
	cin >> n >> d;
	int a[n];
	for (int i = 0; i < n; i++)
		cin >> a[i];
	int prod = 1;
	for (auto& i: a)
		prod *= i;
	cout << prod << '\n';
	return 0;
}