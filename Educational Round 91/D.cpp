#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

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
	ll n, m, x, k, y;
	cin >> n >> m >> x >> k >> y;
	int a[n+2], b[m];
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	a[0] = a[n+1] = 0;
	for (int i = 0; i < m; i++)
		cin >> b[i];
	bool fire = false;
	if (x < k * y)
		fire = true;
	vector<pii> interval;
	int ai = 0, bi = 0;
	while (ai <= n && bi < m) {
		int left = ai;
		while (ai <= n && a[ai] != b[bi]) {
			ai++;
		}
		if (a[ai] != b[bi]) {
			cout << -1 << '\n';
			return 0;
		}
		if (ai - left > 1)
			interval.push_back({left, ai});
		bi++;
	}
	if (bi != m) {
		cout << -1 << '\n';
		return 0;
	}
	if (ai < n)
		interval.push_back({ai, n+1});
	ll ans = 0;
	for (auto& i: interval) {
		int l = i.first;
		int r = i.second;
		int len = r - l - 1;
		int left = a[l];
		int right = a[r];
		int mx = *max_element(a+l+1, a+r);
		if (left > mx || right > mx) {
			if (fire) {
				ans += len / k * x;
				ans += (len % k) * y;
			} else
				ans += len * y;
		} else {
			if (len < k) {
				cout << -1 << '\n';
				return 0;
			}
			if (fire) {
				ans += (len / k) * x;
				ans += (len % k) * y;
			} else {
				ans += x;
				ans += (len - k) * y;
			}
		}
	}
	cout << ans << '\n';
	return 0;
}