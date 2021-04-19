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
		int m;
		cin >> m;
		vector<pair<int, int>> v;
		ll sum = 0;
		for (int i = 0; i < m; i++) {
			ll p, n;
			cin >> p >> n;
			v.push_back({p, n});
			sum += p * n;
		}
		ll ans = 0;
		// print(sum);
		for (ll s = sum; s >= 2; s--) {
			ll divide = s;
			auto cur = v;
			for (auto& i: cur) {
				while (i.second) {
					// print(i.first);
					if (divide % i.first == 0) {
						divide /= i.first;
						i.second--;
					} else
						break;
				}
			}
			if (divide != 1)
				continue;
			ll su = 0;
			for (auto& i: cur) {
				while (i.second) {
					su += i.first;
					i.second--;
				}
			}
			// print(su, s);
			if (su == s) {
				ans = s;
				break;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}