#include <bits/stdc++.h>
using namespace std;

int move(set<int>& piles, multiset<int>& gap) {
	if (piles.size() <= 2)
		return 0;
	int range = *piles.rbegin() - *piles.begin();
	int g = *gap.rbegin();
	return range - g;
}

void update(set<int>& piles, multiset<int>& gap, int t, int x) {
	if (t == 1) {
		auto it = piles.insert(x).first;
		if (it != piles.begin())
			gap.insert(x-*prev(it));
		if (next(it) != piles.end()) {
			gap.insert(*next(it)-x);
			if (it != piles.begin())
				gap.erase(gap.find(*next(it)-*prev(it)));
		}
	} else {
		auto it = piles.find(x);
		if (it != piles.begin())
			gap.erase(gap.find(x-*prev(it)));
		if (next(it) != piles.end()) {
			gap.erase(gap.find(*next(it)-x));
			if (it != piles.begin())
				gap.insert(*next(it)-*prev(it));
		}
		piles.erase(x);
	}
}

int main() {
	int n, q;
	scanf("%d %d", &n, &q);
	set<int> piles;
	multiset<int> gap;
	int p;
	for (int i = 0; i < n; i++) {
		scanf("%d", &p);
		piles.insert(p);
		update(piles, gap, 1, p);
	}
	cout << move(piles, gap) << endl;
	int t, x;
	while (q--) {
		scanf("%d %d", &t, &x);
		update(piles, gap, t, x);
		cout << move(piles, gap) << endl;
	}
	return 0;
}