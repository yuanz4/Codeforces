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
		vector<string> s(n), temp;
		for (int i = 0; i < n; i++)
			cin >> s[i];
		int total = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (s[i][j] == 'X')
					total++;
			}
		}
		for (int sh = 0; sh < 3; sh++) {
			int shift = sh;
			int count = 0;
			temp = s;
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					if (j % 3 == shift) {
						if (temp[i][j] == 'X') {
							temp[i][j] = 'O';
							count++;
						}
					}
				}
				shift = (shift + 1) % 3;
			}
			if (count <= total / 3)
				break;
		}
		for (int i = 0; i < n; i++)
			cout << temp[i] << '\n';
	}
	return 0;
}