#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(0);
    int test;
    cin >> test;
    while (test--) {
    	int n, x, y;
    	cin >> n >> x >> y;
    	int b[n];
        map<int, vector<int>> m;
    	for (int i = 0; i < n; i++) {
    		cin >> b[i];
            m[b[i]].push_back(i);
        }
        int unused = 1;
        for (auto& i: m) {
            if (unused != i.first)
                break;
            unused++;
        }
        map<int, vector<int>> freq;
        int mx = 0;
        for (auto& i: m) {
            mx = max(mx, (int)i.second.size());
            freq[i.second.size()].push_back(i.first);
        }
        int ans[n];
        int count = x;
        while (mx && count) {
            int color = freq[mx].back();
            freq[mx].pop_back();
            if (mx-1)
                freq[mx-1].push_back(color);
            if (freq[mx].empty()) {
                freq.erase(mx);
                mx--;
            }
            int idx = m[color].back();
            m[color].pop_back();
            ans[idx] = b[idx];
            count--;
        }
        if (!freq.empty()) {
            int most_freq = freq.rbegin()->first;
            if (2*most_freq-(n-x) > n-y) {
                cout << "NO" << '\n';
                continue;
            }
        }
        vector<int> order;
        for (auto& i: freq) {
            for (auto& j: i.second) {
                order.insert(order.end(), m[j].begin(), m[j].end());
            }
        }
        int mismatch = n - y;
        for (int i = 0; i < n-x; i++) {
            int idx = (i+(n-x)/2) % (n-x);
            ans[order[i]] = b[order[idx]];
            if (ans[order[i]] == b[order[i]]) {
                mismatch--;
                ans[order[i]] = unused;
            }
        }
        for (int i = 0; i < n-x && mismatch; i++) {
            if (ans[order[i]] != unused) {
                ans[order[i]] = unused;
                mismatch--;
            }
        }
        cout << "YES" << '\n';
        for (int i = 0; i < n; i++)
            cout << ans[i] << ' ';
        cout << '\n';
    }
	return 0;
}