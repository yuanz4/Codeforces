#include <bits/stdc++.h>
using namespace std;

double dfs(vector<int>& a, vector<int>& used, int left, double m) {
	if (left == 0)
		return 0;
	int bzero = -1, zindex = -1;
	int biggest = -1, bindex = -1;
	set<int> avil;
	for (int i = 0; i < a.size(); i++) {
		if (used[i] == 0) {
			avil.insert(i);
			if (a[i]-used[i] > bzero) {
				bzero = a[i]-used[i];
				zindex = i;
			}
		}
		if (a[i]-used[i] > 0) {
			avil.insert(i);
			if (a[i]-used[i] > biggest) {
				biggest = a[i]-used[i];
				bindex = i;
			}
		}
	}
	printf("zero = %d, index = %d\n", zindex, bindex);
	double ret = 0;
	if (zindex != -1) {
		ret += 1;
		if (bindex == -1) {
			used[zindex] += 1;
			ret += dfs(a, used, left-1, m);
			used[zindex] -= 1;
		} else {
			used[bindex] += 1;
			ret += 1 / m * dfs(a, used, left-1, m);
			used[bindex] -= 1;
			used[zindex] += 1;
			ret += (m-1) / m * dfs(a, used, left-1, m);
			used[zindex] -= 1;
		}
	} else {
		int s = avil.size();
		double roll = m / s;
		ret += roll;
		for (int i: avil) {
			used[i] += 1;
			ret += 1 / s * dfs(a, used, left-1, m);
			used[i] -= 1;
		}
	}
	cout << left << " " << ret << endl;
	return ret;
}

int main() {
	int test;
	scanf("%d", &test);
	for (int t = 1; t <= test; t++) {
		int n, m, k;
		cin >> n >> m >> k;
		vector<int> a(k), used(k);
		for (int i = 0; i < k; i++)
			scanf("%d", &a[i]);
		reverse(a.begin(), a.end());
		used[0] = 1;
		double ret = dfs(a, used, n-1, m);
		printf("Case #%d: ", t);
		cout << ret << endl;
	}
	return 0;
}