#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int mx = 2e5+7;
int per[mx];
ll sum[mx];
int n;

void prefix(int start) {
    for (int i = start; i <= n; i++)
        sum[i] = per[i] + sum[i-1];
}

void getPermutation(ll k) {
    ll count = 1;
    int p = 1;
    for (; p < n && count*p <= k; p++)
        count *= p;
    int start = n-p+1;
    int index = start;
    vector<int> all;
    for (int i = 0; i < p; i++)
        all.push_back(start+i);
    while (index <= n) {
        int j = k / count;
        k %= count;
        per[index++] = all[j];
        all.erase(all.begin()+j);
        if (p > 1)
            count /= --p;
    }
    prefix(start);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int q;
    cin >> n >> q;
    int t, l, r, x;
    for (int i = 1; i <= n; i++)
        per[i] = i;
    prefix(1);
    ll k = 0;
    while (q--) {
        cin >> t;
        if (t == 1) {
            cin >> l >> r;
            cout << sum[r] - sum[l-1] << '\n';
        } else {
            cin >> x;
            k += x;
            getPermutation(k);
        }
    }
    return 0;
}