#include <bits/stdc++.h>
using namespace std;

typedef vector<vector<int>> vvi;

int play(vvi v, int choose, vector<int>& perm, int index) {
	if (index == 3) {
		int ret = 0;
		for (int i = 0; i < 3; i++)
			ret += min(v[0][i], v[1][(i+1)%3]);
		return ret;
	}
	int c = (choose >> index) & 1;
	int i = perm[index];
	int smaller = min(v[0][i], v[1][(i-c+3)%3]);
	v[0][i] -= smaller;
	v[1][(i-c+3)%3] -= smaller;
	smaller = min(v[0][i], v[1][(i-(1-c)+3)%3]);
	v[0][i] -= smaller;
	v[1][(i-(1-c)+3)%3] -= smaller;
	return play(v, choose, perm, index+1);
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	int n;
	cin >> n;
	vvi v(2, vector<int>(3));
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 3; j++)
			cin >> v[i][j];
	vector<int> perm = {0, 1, 2};
	int MIN = n;
	do {
		for (int choose = 0; choose < 8; choose++) {
			int ret = play(v, choose, perm, 0);
			MIN = min(MIN, ret);
		}
	} while (next_permutation(perm.begin(), perm.end()));
	int MAX = 0;
	for (int i = 0; i < 3; i++)
			MAX += min(v[0][i], v[1][(i+1)%3]);
	cout << MIN << " " << MAX << '\n';
	return 0;
}