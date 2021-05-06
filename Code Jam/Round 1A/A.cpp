#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// #define DEBUG

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

bool larger(string& a, string& b) {
	if (a.size() > b.size())
		return true;
	if (a.size() < b.size())
		return false;
	return a > b;
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	int test;
	cin >> test;
	for (int t = 1; t <= test; t++) {
		cout << "Case #" << t << ": ";
		int n;
		cin >> n;
		string a[n];
		for (int i = 0; i < n; i++)
			cin >> a[i];
		ll count = 0;
		for (int i = 1; i < n; i++) {
			string x = a[i-1];
			string y = a[i];
			if (larger(y, x))
				continue;
			if (x.size() == y.size()) {
				y += '0';
				count++;
			} else {
				bool big = false;
				bool smaller = false;
				int diff = x.size() - y.size();
				for (int j = 0; j < y.size(); j++) {
					if (x[j] < y[j]) {
						if (!smaller) {
							big = true;
							break;
						}
					}
					if (x[j] > y[j])
						smaller = true;
				}
				if (big) {
					count += diff;
					for (int k = 0; k < diff; k++)
						y += '0';
				} else if (smaller) {
					count += diff + 1;
					for (int k = 0; k < diff + 1; k++)
						y += '0';
				} else {
					bool full = true;
					for (int k = 0; k < diff; k++) {
						int pos = k + y.size();
						if (x[pos] != '9') {
							full = false;
							break;
						}
					}
					print(p);
					if (!full) {
						y = x;
						int carry = 1;
						for (int i = x.size() - 1; i >= 0; i--) {
							if (carry == 0)
								break;
							if (y[i] == '9')
								y[i] = '0';
							else {
								y[i] += 1;
								carry = 0;
							}
						}
						count += diff;
					} else {
						count += diff + 1;
						for (int k = 0; k < diff + 1; k++)
							y += '0';
					}
				}
			}
			print(y);
			a[i] = y;
		}
		cout << count << '\n';
	}
	return 0;
}