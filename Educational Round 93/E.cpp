#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n;
set <int> sDouble;
ll sum[2];
set <int> s[2];
int cntDouble[2];

void upd(int id) {
	int x;
	if (id == 0)
		x = *s[0].rbegin();
	else
		x = *s[1].begin();
	bool d = sDouble.count(x);
	sum[id] -= x, sum[!id] += x;
	s[id].erase(x), s[!id].insert(x);
	cntDouble[id] -= d, cntDouble[!id] += d;
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	cin >> n;
	while (n--) {
		int tp, x;
		cin >> tp >> x;
		if (x > 0) {
			sum[0] += x;
			s[0].insert(x);
			cntDouble[0] += tp;
			if (tp)
				sDouble.insert(x);
		} else {
			x = -x;
			int id = 0;
			if (s[1].count(x))
				id = 1;
			sum[id] -= x;
			s[id].erase(x);
			cntDouble[id] -= tp;
			if (tp)
				sDouble.erase(x);
		}
		int sumDouble = cntDouble[0] + cntDouble[1];
		if (s[1].size() < sumDouble)
			upd(0);
		if (s[1].size() > sumDouble)
			upd(1);
		if (s[1].size() > 0 && s[0].size() > 0 && *s[0].rbegin() > *s[1].begin()) {
            upd(0);
            upd(1);
        }
		ll res = sum[0] + sum[1] * 2;
		if (cntDouble[1] == sumDouble && sumDouble > 0) {
			res -= *s[1].begin();
			if (s[0].size() > 0)
				res += *s[0].rbegin();
		}
		cout << res << '\n';
	}
	return 0;
}