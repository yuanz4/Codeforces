#include <bits/stdc++.h>
using namespace std;

int main() {
	int test;
	scanf("%d", &test);
	while (test--) {
		string s;
		cin >> s;
		int ret = 0;
		multiset<int> set;
		int count = 0;
		for (char c: s) {
			if (c == '1') {
				count++;
			} else {
				if (count) {
					set.insert(count);
					count = 0;
				}
			}
		}
		if (count)
			set.insert(count);
		bool alice = true;
		for (auto it = set.rbegin(); it != set.rend(); it++) {
			if (alice)
				ret += *it;
			alice = !alice;
		}
		printf("%d\n", ret);
	}
	return 0;
}