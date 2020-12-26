#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	int r, g, b;
	scanf("%d %d %d", &r, &g, &b);
	int R[r], G[g], B[b];
	for (int i = 0; i < r; i++)
		scanf("%d", &R[i]);
	sort(R, R+r);
	for (int i = 0; i < g; i++)
		scanf("%d", &G[i]);
	sort(G, G+g);
	for (int i = 0; i < b; i++)
		scanf("%d", &B[i]);
	sort(B, B+b);
	int d[r+1][g+1][b+1] = {};
	int ret = 0;
	for (int i = 0; i <= r; i++) {
		for (int j = 0; j <= g; j++) {
			for (int k = 0; k <= b; k++) {
				if (i < r && j < g)
					d[i+1][j+1][k] = max(d[i+1][j+1][k], d[i][j][k]+R[i]*G[j]);
				if (i < r && k < b)
					d[i+1][j][k+1] = max(d[i+1][j][k+1], d[i][j][k]+R[i]*B[k]);
				if (j < g && k < b)
					d[i][j+1][k+1] = max(d[i][j+1][k+1], d[i][j][k]+G[j]*B[k]);
				ret = max(ret, d[i][j][k]);
			}
		}
	}
	printf("%d\n", ret);
	return 0;
}