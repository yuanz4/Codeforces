#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void fail() {
	cout << "invalid" << '\n';
	exit(0);
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(0);
    vector<string> grid(8);
	for (auto& i: grid)
		cin >> i;
	int total = 0;
	for (int i = 0; i < 8; i++) {
		int count = 0;
		for (int j = 0; j < 8; j++) {
			if (grid[i][j] == '*') {
				count++;
				total++;
			}
		}
		if (count > 1)
			fail();
	}
	if (total != 8)
		fail();
	for (int i = 0; i < 8; i++) {
		int count = 0;
		for (int j = 0; j < 8; j++) {
			if (grid[j][i] == '*')
				count++;
		}
		if (count > 1)
			fail();
	}

	for (int i = 0; i < 8; i++) {
		int count = 0;
		for (int j = 0; j < 8 - i; j++) {
			if (grid[j][i+j] == '*')
				count++;
		}
		if (count > 1)
			fail();
	}
	for (int i = 1; i < 8; i++) {
		int count = 0;
		for (int j = 0; j < 8 - i; j++) {
			if (grid[i+j][j] == '*')
				count++;
		}
		if (count > 1)
			fail();
	}

	for (int i = 0; i < 8; i++) {
		int count = 0;
		for (int j = 0; j < 8 - i; j++) {
			if (grid[j][7-j-i] == '*')
				count++;
		}
		if (count > 1)
			fail();
	}
	for (int i = 1; i < 8; i++) {
		int count = 0;
		for (int j = 0; j < 8 - i; j++) {
			if (grid[i+j][7-j] == '*')
				count++;
		}
		if (count > 1)
			fail();
	}
	cout << "valid" << '\n';
	return 0;
}