#include <bits/stdc++.h>
using namespace std;

bool next(vector<int>& p) {
	int n = p.size();
	int carry = 1;
	for (int i = 0; i < n; i++) {
		p[i] += carry;
		if (p[i] == n+1) {
			carry = 1;
			p[i] = 1;
		} else {
			return true;
		}
	}
	return false;
}

int main() {
	int test;
	scanf("%d", &test);
	for (int t = 1; t <= test; t++) {
		printf("Case #%d:", t);
		int N, A, B, C;
		cin >> N >> A >> B >> C;
		vector<int> p(N, 1);
		int count = 0;
		do {
			int prev = p[0];
			unordered_set<int> left({0});
			for (int i = 1; i < N; i++) {
				if (p[i] >= prev) {
					left.insert(i);
					prev = p[i];
				}
			}
			int a = left.size(), b = 1, c = 0;
			int after = p[N-1];
			if (left.count(N-1))
				c++;
			for (int i = N-2; i >= 0; i--) {
				if (p[i] >= after) {
					b++;
					if (left.count(i))
						c++;
					after = p[i];
				}
			}
			if (a == A && b == B && c == C) {
				for (int i = 0; i < N; i++) {
					cout << " " << p[i];
				}
				cout << endl;
				goto next;
			}
		} while (next(p));
		printf(" IMPOSSIBLE\n");
		next:;
	}
	return 0;
}