#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define left(v) (v << 1)
#define right(v) ((v << 1) + 1)
#define all(v) v.begin(), v.end()
const int MAXN = 1e5 + 7;
const int MAXP = sqrt(2e5 + 7);
const int MOD = 1e9 + 7;

vector<int> prime;
unordered_map<int, int> last;
vector<int> seq;
vector<int> upd(MAXP);
vector<int> val(MAXP);
int ver = 0;
ll ans = 0;

struct node {
	vector<pair<int, int>> low;
	vector<pair<int, int>> high;
	vector<int> prod;
} t[4*MAXN];

void sieve(int n) {
	vector<bool> is_prime(n+1, true);
	is_prime[0] = is_prime[1] = false;
	for (int i = 2; i <= n; i++) {
		if (is_prime[i]) {
			prime.push_back(i);
			for (int j = i*i; j <= n; j += i)
				is_prime[j] = false;
		}
	}
}

void combine_low(node& l, node& r, node& v) {
	auto li = l.low.begin();
    auto ri = r.low.begin();
    auto lend = l.low.end();
    auto rend = r.low.end();
    while (li != lend || ri != rend) {
        if (ri == rend || (li != lend && li->first < ri->first)) {
            v.low.push_back({li->first, li->second});
            li++;
        } else if (li == lend || (ri != rend && ri->first < li->first)) {
            v.low.push_back({ri->first, ri->second});
            ri++;
        } else {
            v.low.push_back({li->first, max(li->second, ri->second)});
            li++;
            ri++;
        }
    }
}

void merge_node(node& l, node& r, node& v) {
	combine_low(l, r, v);
	merge(all(l.high), all(r.high), back_inserter(v.high));
	ll p = 1;
	for (auto& [_, i]: v.high) {
		p = p * i % MOD;
		v.prod.push_back(p);
	}
}

void build(int v, int tl, int tr) {
	if (tl == tr) {
		int a;
		cin >> a;
		for (auto& i: prime) {
			int cnt = 0;
			while (a % i == 0) {
				a /= i;
				cnt++;
			}
			if (cnt)
				t[v].low.push_back({i, cnt});
		}
		if (a > 1) {
			if (a > MAXP) {
				int prev = -1;
				if (last.count(a))
					prev = last[a];
				t[v].high.push_back({prev, a});
				t[v].prod.push_back(a);
				last[a] = tl;
			} else
				t[v].low.push_back({a, 1});
		}
		return;
	}
	int tm = (tl + tr) / 2;
	build(left(v), tl, tm);
	build(right(v), tm+1, tr);
	merge_node(t[left(v)], t[right(v)], t[v]);
}

void get(int v, int tl, int tr, int l, int r, int bound) {
	if (l > r)
		return;
	if (l == tl && r == tr) {
		for (auto& [i, p]: t[v].low) {
			if (upd[i] != ver) {
				upd[i] = ver;
				seq.push_back(i);
				val[i] = 0;
			}
			val[i] = max(val[i], p);
		}
		int pos = lower_bound(all(t[v].high), make_pair(bound, 0))
			- t[v].high.begin();
		if (pos)
			ans = ans * t[v].prod[pos-1] % MOD;
		return;
	}
	int tm = (tl + tr) / 2;
	get(left(v), tl, tm, l, min(tm, r), bound);
	get(right(v), tm+1, tr, max(l, tm+1), r, bound);
}

ll powmod(ll a, ll b) {
	ll res = 1;
	a %= MOD;
	for (; b; b >>= 1) {
		if (b & 1)
			res = res * a % MOD;
		a = a * a % MOD;
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	int n;
	cin >> n;
	sieve(MAXP);
	build(1, 0, n-1);
	int q;
	cin >> q;
	while (q--) {
		ver++;
		int l, r;
		cin >> l >> r;
		l = (ans + l) % n;
		r = (ans + r) % n;
		if (l > r)
			swap(l, r);
		ans = 1;
		seq.clear();
		get(1, 0, n-1, l, r, l);
		for (auto& i: seq)
			ans = ans * powmod(i, val[i]) % MOD;
		cout << ans << '\n';
	}
	return 0;
}