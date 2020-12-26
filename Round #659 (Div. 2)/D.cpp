#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
    	int n;
    	cin >> n;
    	int a[n];
    	int x = 0;
    	for (int i = 0; i < n; i++) {
    		cin >> a[i];
    		x ^= a[i];
    	}
    	if (x == 0)
    		cout << "DRAW" << '\n';
    	else {
    		for (int i = 30; i >= 0; i--) {
    			if ((x >> i) & 1) {
    				int one = 0;
    				for (int j = 0; j < n; j++)
    					one += (a[j] >> i) & 1;
    				int zero = n - one;
    				if (one % 4 == 3 && zero % 2 == 0)
    					cout << "LOSE" << '\n';
    				else
    					cout << "WIN" << '\n';
    				break;
    			}
    		}
    	}
    }
	return 0;
}