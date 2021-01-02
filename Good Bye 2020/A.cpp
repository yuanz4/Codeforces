#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	int test;
	cin >> test;
	while (test--) {
		int n;
		cin >> n;
		int x[n];
		for (int i = 0; i < n; i++)
			cin >> x[i];
		unordered_set<int> s;
		for (int i = 0; i < n; i++) {
			for (int j = i+1; j < n; j++) {
				s.insert(x[j] - x[i]);
			}
		}
		cout << s.size() << '\n';
	}
	return 0;
}