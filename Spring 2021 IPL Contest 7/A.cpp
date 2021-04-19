#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n;

void first(vector<int>& a) {
	for (int i = 0; i < n; i++)
		swap(a[2*i], a[2*i+1]);
}

void second(vector<int>& a) {
	for (int i = 0; i < n; i++)
		swap(a[i], a[i+n]);
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	cin >> n;
	vector<int> a(2 * n);
	for (int i = 0; i < 2 * n; i++)
		cin >> a[i];
	bool ok = false;
	int cycle;
	if (n % 2)
		cycle = n;
	else
		cycle = 2;
	vector<int> b = a;
	int count = 0;
	if (is_sorted(b.begin(), b.end()))
			ok = true;
	else {
		for (int i = 0; i < cycle; i++) {
			first(b);
			count++;
			if (is_sorted(b.begin(), b.end())) {
				ok = true;
				break;
			}
			second(b);
			count++;
			if (is_sorted(b.begin(), b.end())) {
				ok = true;
				break;
			}
		}
	}
	if (ok)
		cout << min(count, 2 * cycle - count) << '\n';
	else
		cout << -1 << '\n';
	return 0;
}