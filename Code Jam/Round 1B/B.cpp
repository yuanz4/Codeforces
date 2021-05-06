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

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	int test;
	cin >> test;
	for (int t = 1; t <= test; t++) {
		cout << "Case #" << t << ": ";
		int n, a, b;
		cin >> n >> a >> b;
		int x[n];
		for (int i = 0; i < n; i++)
			cin >> x[i];
		int max = n;
		for (int i = n - 1; i >= 0; i--) {
			if (x[i]) {
				max = i;
				break;
			}
		}
		bool found = false;
		int MAX = 5000;
		for (int total = max + 1; total <= MAX; total++) {
			vector<int> m(total);
			m[total-1] = 1;
			bool ok = true;
			for (int i = total - 1; i >= 0; i--) {
				int first = i - b;
				int second = i - a;
				int cost = m[i];
				if (i < n) {
					if (m[i] < x[i]) {
						ok = false;
						break;
					}
					cost = m[i] - x[i];
				}
				m[i] -= cost;
				if (first >= 0)
					m[first] += cost;
				if (second >= 0)
					m[second] += cost;
			}
			if (ok) {
				cout << total << '\n';
				found = true;
				break;
			}
		}
		if (!found)
			cout << "IMPOSSIBLE" << '\n';
	}
	return 0;
}