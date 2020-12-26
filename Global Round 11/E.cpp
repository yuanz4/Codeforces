#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct op {
	ll i, j;
	char c;
	op(ll i, char c, ll j) : i(i), j(j), c(c) {}
	friend ostream& operator<<(ostream& os, const op& a) {
	    return os << a.i << " " << a.c << " " << a.j;
	}
};

vector<op> v;

ll mul(ll a, ll b) {
	stack<ll> s;
	ll res = 0;
	for (; b; b >>= 1) {
		if (b & 1)
			s.push(a);
		v.emplace_back(a, '+', a);
		a += a;
	}
	res = s.top();
	s.pop();
	v.pop_back();
	while (!s.empty()) {
		ll top = s.top();
		s.pop();
		v.emplace_back(res, '+', top);
		res += top;
	}
	return res;
}

ll exgcd(ll a, ll b, ll& x, ll& y) {
	if (b == 0) {
		x = 1, y = 0;
		return a;
	}
	ll d = exgcd(b, a%b, x, y);
	ll z = x;
	x = y;
	y = z - y * (a / b);
	return d;
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	ll a;
	cin >> a;
	ll e = log2(a);
	ll b = mul(a, 1<<e);
	v.emplace_back(b, '^', a);
	b ^= a;
	ll x, y;
	ll d = exgcd(a, b, x, y);
	y = -y;
	while (x <= 0 || y <= 0 || y % 2 != 0) {
		x += b;
		y += a;
	}
	ll ax = mul(a, x);
	ll by = mul(b, y);
	v.emplace_back(ax, '^', by);
	assert((a*x) ^ (b*y) == 1);
	cout << v.size() << '\n';
	for (auto& i: v)
		cout << i << '\n';
	return 0;
}