#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define DEBUG

void debug_out() {cerr << endl;}

template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {cerr << " " << H, debug_out(T...);}

#ifdef DEBUG
#define print(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define print(...)
#endif

template<typename T>
ostream& operator<<(ostream& os, const vector<T>& v) {
    os << '[';
    string sep;
    for (const auto& x: v)
        os << sep << x, sep = ", ";
    return os << ']';
}

template<typename A, typename B>
ostream& operator<<(ostream& os, const pair<A, B>& p) {
    return os << '(' << p.first << ", " << p.second << ')';
}

void flip(string& s) {
	for (char& i: s) {
		if (i == 'T')
			i = 'F';
		else
			i = 'T';
	}
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	int test;
	cin >> test;
	for (int t = 1; t <= test; t++) {
		cout << "Case #" << t << ": ";
		int n, q;
		cin >> n >> q;
		string a[n];
		int s[n];
		for (int i = 0; i < n; i++)
			cin >> a[i] >> s[i];
		if (n == 1) {
			if (s[0] < (q + 1) / 2) {
				flip(a[0]);
				cout << a[0] << " " << q - s[0] << "/1" << '\n';
			} else
				cout << a[0] << " " << s[0] << "/1" << '\n';
		}
		else {
			for (int i = 0; i < n; i++) {
				if (s[i] < (q + 1) / 2) {
					flip(a[i]);
					s[i] = q - s[i];
				}
			}
			int same = 0;
			int x = s[0], y = s[1];
			string u = a[0], v = a[1];
			if (x < y) {
				swap(x, y);
				swap(u, v);
			}
			vector<int> dif, sam;
			for (int i = 0; i < q; i++) {
				if (u[i] == v[i]) {
					same++;
					sam.push_back(i);
				} else
					dif.push_back(i);
			}
			int f = q - same;
			int diff = x - y + f;
			assert(diff % 2 == 0);
			int good = diff / 2;
			int remain = x - good;
			string ans = u;
			if (remain < (same + 1) / 2) {
				for (auto& i: sam) {
					if (ans[i] == 'T')
						ans[i] = 'F';
					else
						ans[i] = 'T';
				}
				remain = same - remain;
			}
			cout << ans << " " << remain + good << "/1" << '\n';
			// print(good);
			// print(same, f, q, x, y);
			// print(a[0], s[0]);
			// print(a[1], s[1]);
		}
	}
	return 0;
}