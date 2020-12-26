#include <bits/stdc++.h>
using namespace std;

int main() {
	int test;
	scanf("%d", &test);
	for (int t = 1; t <= test; t++) {
		int s, ra, pa, rb, pb, c;
		cin >> s >> ra >> pa >> rb >> pb >> c;
		int r, p;
		vector<pair<int, int>> con(c);
		for (int i = 0; i < c; i++) {
			scanf("%d %d", &r, &p);
			con[i] = {r, p};
		}
		int ret = 0;
		if (ra == 2 && pa == 2)
			ret = c == 2? 0 : 1;
		else if (rb == 2 && pb == 2) {
			ret = c == 2? 0 : -1;
		} else {
			if (c == 0)
				ret = 2;
			else if (c == 2)
				ret = 0;
			else {
				if (con[0].first == 2 && con[0].second == 2)
					ret = 0;
				else
					ret = 1;
			}
		}
		printf("Case #%d: %d\n", t, ret);
	}
	return 0;
}