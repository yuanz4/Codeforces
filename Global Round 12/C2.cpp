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
		vector<string> s(n), temp1, temp2;
		for (int i = 0; i < n; i++)
			cin >> s[i];
		int total = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (s[i][j] != '.')
					total++;
			}
		}
		for (int x = 0; x < 3; x++) {
			int count1 = 0;
			int shift = x;
			temp1 = s;
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					if (j % 3 == shift) {
						if (temp1[i][j] == 'O') {
							temp1[i][j] = 'X';
							count1++;
						}
					}
				}
				shift = (shift + 1) % 3;
			}
			bool ok = false;
			for (int o = 0; o < 3; o++) {
				if (o == x)
					continue;
				shift = o;
				temp2 = temp1;
				int count2 = count1;
				for (int i = 0; i < n; i++) {
					for (int j = 0; j < n; j++) {
						if (j % 3 == shift) {
							if (temp2[i][j] == 'X') {
								temp2[i][j] = 'O';
								count2++;
							}
						}
					}
					shift = (shift + 1) % 3;
				}
				if (count2 <= total / 3)
					ok = true;
					break;
			}
			if (ok)
				break;
		}
		for (int i = 0; i < n; i++)
			cout << temp2[i] << '\n';
	}
	return 0;
}