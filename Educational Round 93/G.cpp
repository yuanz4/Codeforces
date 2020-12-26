#include <bits/stdc++.h>
using namespace std;

const int K = 2e5+7;
const int M = 1e6+7;
const int N = 1 << 19;
bool good[M];
int dp[M];

using cd = complex<double>;
const double PI = acos(-1);

void fft(vector<cd> & a, bool invert) {
    int n = a.size();

    for (int i = 1, j = 0; i < n; i++) {
        int bit = n >> 1;
        for (; j & bit; bit >>= 1)
            j ^= bit;
        j ^= bit;

        if (i < j)
            swap(a[i], a[j]);
    }

    for (int len = 2; len <= n; len <<= 1) {
        double ang = 2 * PI / len * (invert ? -1 : 1);
        cd wlen(cos(ang), sin(ang));
        for (int i = 0; i < n; i += len) {
            cd w(1);
            for (int j = 0; j < len / 2; j++) {
                cd u = a[i+j], v = a[i+j+len/2] * w;
                a[i+j] = u + v;
                a[i+j+len/2] = u - v;
                w *= wlen;
            }
        }
    }

    if (invert) {
        for (cd & x : a)
            x /= n;
    }
}

vector<int> multiply(vector<int> const& a, vector<int> const& b) {
    vector<cd> fa(a.begin(), a.end()), fb(b.begin(), b.end());
    int n = 1;
    while (n < a.size() + b.size()) 
        n <<= 1;
    fa.resize(n);
    fb.resize(n);

    fft(fa, false);
    fft(fb, false);
    for (int i = 0; i < n; i++)
        fa[i] *= fb[i];
    fft(fa, true);

    vector<int> result(n);
    for (int i = 0; i < n; i++)
        result[i] = round(fa[i].real());
    return result;
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	int n, x, y;
	cin >> n >> x >> y;
	int temp;
	vector<int> a(N), b(N);
	for (int i = 0; i <= n; i++) {
		cin >> temp;
		a[temp] = 1;
		b[K-temp] = 1;
	}
	vector<int> ret = multiply(a, b);
	for (int i = K+1; i <= 2*K; i++) {
		if (ret[i])
			good[(i-K+y)*2] = true;
	}
	for (int i = 0; i < M; i++)
		dp[i] = -1;
	for (int i = 0; i < M; i++) {
		if (good[i]) {
			for (int j = i; j < M; j += i)
				dp[j] = max(dp[j], i);
		}
	}
	int q;
	cin >> q;
	while (q--) {
		int l;
		cin >> l;
		cout << dp[l] << ' ';
	}
	cout << '\n';
	return 0;
}