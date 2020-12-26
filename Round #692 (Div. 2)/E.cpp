#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	ll n, T;
	cin >> n >> T;
	string s;
	cin >> s;
	T -= 1 << (s[n-1] - 'a');
	T += 1 << (s[n-2] - 'a');
	s.pop_back();
	s.pop_back();
	int cnt[27] = {};
	for (char c: s) {
		int idx = c - 'a';
		T += 1 << idx;
		cnt[idx+1]++;
	}
	cout << ([&]() -> bool {
		if (T < 0)
			return false;
		for (int i = 0; i < 26; i++) {
			if (T & 1) {
				if (!cnt[i])
					return false;
				cnt[i]--;
				T--;
			}
			T >>= 1;
			cnt[i+1] += cnt[i] >> 1;
		}
		return true;
	}() ? "Yes" : "No") << '\n';
	return 0;
}