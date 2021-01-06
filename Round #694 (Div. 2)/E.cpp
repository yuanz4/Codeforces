#include <bits/stdc++.h>
using namespace std;

#define TEST
#define DEBUG

typedef long long ll;
unsigned seed = chrono::system_clock::now().time_since_epoch().count();
mt19937 rng(seed);

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	int n, k;
	cin >> n >> k;
	#ifdef TEST
	int p = rng() % n;
	vector<int> a(n, k), b(n);
	#endif

	auto ask = [&](int pos) {
		int card;
		#ifdef TEST
		#ifdef DEBUG
		for (int i = 0; i < n; i++) {
			if (i == p)
				cout << "|" << a[i] << "| ";
			else
				cout << a[i] << ' ';
		}
		cout << '\n';
		#endif
		card = a[pos];
		b.assign(n, 0);
		for (int i = 0; i < n; i++) {
			if (i == p)
				b[(i+1)%n] += a[i];
			else {
				b[(i-1+n)%n] += a[i] / 2;
				b[(i+1)%n] += (a[i] + 1) / 2;
			}
		}
		a = b;
		#else
		cout << "? " << pos + 1 << endl;
		cin >> card;
		#endif
		return card;
	};
	
	int block = sqrt(n);
	ask(0);
	for (int i = 0; i < block; i++)
		ask(0);
	int smaller = 0;
	for (; smaller < n; smaller += block) {
		if (ask(smaller) < k)
			break;
	}
	int len = (n - 1) / 2;
	int low = smaller, high = smaller + len;
	int ans;
	while (low <= high) {
		int mid = (low + high) / 2;
		int card = ask(mid % n);
		if (card == k) {
			ans = mid % n;
			high = mid - 1;
		} else if (card < k)
			low = mid + 1;
		else
			high = mid - 1;
	}
	#ifdef TEST
	assert(ans == p);
	#endif
	cout << "! " << ans + 1 << '\n';
	return 0;
}