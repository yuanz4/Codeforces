#include <bits/stdc++.h>
using namespace std;

int main() {
	int test;
	scanf("%d", &test);
	while (test--) {
		int n;
		scanf("%d", &n);
		string s, ret;
		cin >> s;
		for (int i = 0; i < s.size(); i+=2)
			ret += s[i];
		cout << ret << endl;
	}
	return 0;
}