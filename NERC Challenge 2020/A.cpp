#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second

int n, m;
vector<pair<int, int>> server, vm, pos;
vector<set<int>> state;

struct op {
	int i = 0, j = 0, k = 0;
	op() {}
	op(int i, int j, int k) : i(i), j(j), k(k) {}
	friend bool operator< (const op& a, const op& b) {
		vector<int> v1{a.i, a.j, a.k};
		vector<int> v2{b.i, b.j, b.k};
		return v1 < v2;
	}
	friend ostream& operator<<(ostream& os, const op& a) {
        os << a.i << " " << a.j << " " << a.k;
        return os;
    }
};

void print() {
	for (int i = 0; i < n; i++) {
		cout << "------server " << i << " remain: ";
		cout << server[i].x << " " << server[i].y;
		cout << "------" << '\n';
		for (auto& j: state[i]) {
			cout << "vm " << j << ": ";
			cout << vm[j].x << " " << vm[j].y;
			cout << ", optimal: " << pos[j].y << '\n';
		}
	}
}

bool update(op cur) {
	if (server[cur.j].x < vm[cur.k].x || server[cur.j].y < vm[cur.k].y)
		return false;
	state[cur.i].erase(cur.k);
	server[cur.i].x += vm[cur.k].x;
	server[cur.i].y += vm[cur.k].y;
	state[cur.j].insert(cur.k);
	server[cur.j].x -= vm[cur.k].x;
	server[cur.j].y -= vm[cur.k].y;
	return true;
}

void solution() {
	int s;
	cin >> s;
	vector<vector<op>> sol(s);
	for (int i = 0; i < s; i++) {
		int k;
		cin >> k;
		for (int j = 0; j < k; j++) {
			op cur;
			cin >> cur.i >> cur.j >> cur.k;
			sol[i].push_back(cur);
		}
	}
	cout << "++++++initial++++++" << '\n';
	print();
	cout << '\n';
	for (int i = 0; i < s; i++) {
		cout << "++++++step " << i+1 << "++++++" << '\n';
		for (auto& j: sol[i])
			update(j);
		print();
		cout << '\n';
	}
}

vector<vector<op>> compress(vector<op>& ans) {
	vector<vector<op>> final;
	unordered_map<int, int> m;
	vector<op> cur;
	for (auto& i: ans) {
		if (m[i.i] || m[i.j]) {
			final.push_back(cur);
			cur.clear();
			m.clear();
		}
		cur.push_back(i);
		m[i.i]++;
		m[i.j]++;
	}
	final.push_back(cur);
	return final;
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	cin >> n >> m;
	server.resize(n);
	vm.resize(m);
	pos.resize(m);
	state.resize(n);
	for (int i = 0; i < n; i++)
		cin >> server[i].x >> server[i].y;
	for (int i = 0; i < m; i++)
		cin >> vm[i].x >> vm[i].y;
	set<op> task;
	for (int i = 0; i < m; i++) {
		cin >> pos[i].x >> pos[i].y;
		server[pos[i].x].x -= vm[i].x;
		server[pos[i].x].y -= vm[i].y;
		if (pos[i].x != pos[i].y) {
			state[pos[i].x].insert(i);
			task.insert({pos[i].x, pos[i].y, i});
		}
	}
	// solution();
	// print();
	vector<op> ans;
	while (task.size()) {
		bool ok = false;
		for (auto cur: task) {
			if (update(cur)) {
				ok = true;
				ans.push_back(cur);
				task.erase(cur);
				break;
			}
		}
		if (!ok) {
			for (auto& cur: task) {
				for (int i = 0; i < n; i++) {
					op temp{cur.i, i, cur.k};
					if (update(temp)) {
						ans.push_back(temp);
						task.erase(cur);
						task.insert({i, cur.j, cur.k});
						break;
					}
				}
			}
		}
	}

	vector<vector<op>> final = compress(ans);
	cout << final.size() << '\n';
	for (auto& i: final) {
		cout << i.size() << '\n';
		for (auto& j: i)
			cout << j << '\n';
	}

	// cout << ans.size() << '\n';
	// for (auto& i: ans) {
	// 	cout << 1 << '\n';
	// 	cout << i.i << " " << i.j << " " << i.k << '\n';
	// }
	return 0;
}