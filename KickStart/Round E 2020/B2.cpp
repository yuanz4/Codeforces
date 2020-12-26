#include <bits/stdc++.h>
using namespace std;

int main() {
	int test;
	scanf("%d", &test);
	for (int t = 1; t <= test; t++) {
		printf("Case #%d:", t);
		int N, A, B, C;
		cin >> N >> A >> B >> C;
		vector<int> v(N, 0);
		int left = A - C;
		int right = B - C;
		int hide = N + C - A - B;
		bool possible = true;
		if (hide >= 0) {
			for (int i = 0; i < left; i++)
				v[i] = i+N-left;
			for (int i = 0; i < right; i++)
				v[N-1-i] = i+N-right;
			if (C >= 2) {
				v[left] = N;
				v[N-1-right] = N;
				int c = C - 2;
				for (int i = left+1; i < N-1-right; i++) {
					if (c-- > 0)
						v[i] = N;
					else
						v[i] = 1;
				}
			} else {
				if (hide == 0) {
					v[left] = N;
				} else if (left > 0) {
					for (int i = 0; i < hide; i++)
						v[left+i] = 1;
					v[left+hide] = N;
				} else if (right > 0) {
					for (int i = 0; i < hide; i++)
						v[N-1-right-i] = 1;
					v[N-1-right-hide] = N;
				} else {
					possible = false;
				}
			}
		} else {
			possible = false;
		}
		if (possible) {
			for (int i = 0; i < N; i++)
				printf(" %d", v[i]);
			printf("\n");
		} else
			printf(" IMPOSSIBLE\n");
	}
	return 0;
}