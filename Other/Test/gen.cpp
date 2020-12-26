#include <bits/stdc++.h>
using namespace std;

int rand(int a, int b) {
	return a + rand() % (b - a + 1);
}

char c() {
	string s = "abcdefghijklmnopqrstuvwxyz";
	return s[rand(0, 25)];
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(0);
    srand(time(NULL));
	int n = rand(2, 11);
	cout << n << '\n';
	unordered_set<int> used;
	for (int i = 0; i < n; i++) {
		int x;
		do {
			// x = c();
			x = rand(1, 10);
		} while (used.count(x));
		cout << x << " ";
		used.insert(x);
	}
	cout << '\n';
	return 0;
}