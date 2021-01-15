#include <bits/stdc++.h>
using namespace std;

const int MAX = 1000;
char g[2*MAX+2][2*MAX+2];
int p[5*MAX*MAX];

int get(int x) {
	if (p[x] == x)
		return x;
	return p[x] = get(p[x]);
}

bool merge(int x, int y) {
	x = get(x);
	y = get(y);
	if (x == y)
		return false;
	p[y] = x;
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	int r, c;
	cin >> r >> c;
	memset(g, '.', sizeof(g));
	for (int i = 0; i < r; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < c; j++) {
			if (s[j] == '.')
				continue;
			if (s[j] == '/') {
				g[2*i+2][2*j+1] = '#';
				g[2*i+1][2*j+2] = '#';
			} else {
				g[2*i+1][2*j+1] = '#';
				g[2*i+2][2*j+2] = '#';
			}
		}
	}
	int R = 2 * r + 2;
	int C = 2 * c + 2;
	int comps = 0;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cout << g[i][j] << ' ';
			if (g[i][j] == '#')
				continue;
			comps++;
			p[i*C+j] = i*C+j;
			if (i && g[i-1][j] == '.' && merge((i-1)*C+j, i*C+j))
				comps--;
			if (j && g[i][j-1] == '.' && merge(i*C+(j-1), i*C+j))
				comps--;
		}
		cout << '\n';
	}
	cout << comps - 1 << '\n';
	return 0;
}