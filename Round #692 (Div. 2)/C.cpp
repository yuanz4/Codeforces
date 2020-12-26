#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	int test;
	cin >> test;
	while (test--) {
		int n, m;
		cin >> n >> m;
		int x[m], y[m];
		unordered_set<int> row, col, empty;
		unordered_map<int, int> chess, chessi;
		int a, b;
		for (int i = 0; i < n; i++)
			empty.insert(i);
		for (int i = 0; i < m; i++) {
			cin >> a >> b;
			a--, b--;
			chess[a] = b;
			chessi[b] = a;
			row.insert(a);
			col.insert(b);
			empty.erase(a);
			empty.erase(b);
		}
		int count = 0;
		a = -1, b = -1;
		while (chess.size()) {
			if (a != -1) {
				if (col.count(a)) {
					int c = chessi[a];
					row.erase(c);
					row.insert(a);
					if (!col.count(c))
						empty.insert(c);
					chess.erase(c);
					chessi.erase(a);
					a = c;
					count++;
					continue;
				} else
					a = -1;
			}
			if (b != -1) {
				if (row.count(b)) {
					int c = chess[b];
					col.erase(c);
					col.insert(b);
					if (!row.count(c))
						empty.insert(c);
					chess.erase(b);
					chessi.erase(c);
					b = c;
					count++;
					continue;
				} else
					b = -1;
			}
			bool ok = false;
			for (auto& i: chess) {
				if (i.first == i.second) {
					chess.erase(i.first);
					chessi.erase(i.second);
					ok = true;
					break;
				}
				if (!col.count(i.first)) {
					col.erase(i.second);
					col.insert(i.first);
					if (!row.count(i.second))
						empty.insert(i.second);
					b = i.second;
					chess.erase(i.first);
					chessi.erase(i.second);
					ok = true;
					count++;
					break;
				}
				if (!row.count(i.second)) {
					row.erase(i.first);
					row.insert(i.second);
					if (!col.count(i.first))
						empty.insert(i.first);
					a = i.first;
					chess.erase(i.first);
					chessi.erase(i.second);
					ok = true;
					count++;
					break;
				}
			}
			if (ok)
				continue;
			auto i = *chess.begin();
			int avail = *empty.begin();
			empty.erase(avail);
			row.erase(i.first);
			col.erase(i.second);
			row.insert(avail);
			col.insert(avail);
			a = i.first;
			b = i.second;
			chess.erase(i.first);
			chessi.erase(i.second);
			count += 2;
		}
		cout << count << '\n';
	}
	return 0;
}